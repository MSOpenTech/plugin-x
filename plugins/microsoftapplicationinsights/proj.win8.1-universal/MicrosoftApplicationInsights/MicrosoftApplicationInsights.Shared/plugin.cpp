
/****************************************************************************
Copyright (c) 2012-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.
Copyright (c) Microsoft Corporation.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "pch.h"

#include <unordered_map>
#include <Windows.h>
#include <cstdio>


using namespace cocosPluginWinrtBridge;
using namespace Microsoft::ApplicationInsights;

#define NANOSECONDS_PER_MILLISECOND 1000000

namespace microsoftapplicationinsights {
    public ref class microsoftapplicationinsights sealed : public IProtocolAnalytics {
    private:
        std::unordered_map<Platform::String^, Windows::Foundation::TimeSpan*> timedEvents;
        bool debugMode;
        TelemetryClient^ telemetryClient;
    public:

        microsoftapplicationinsights() {
            debugMode = false;
            telemetryClient = nullptr;
        }

        /**
        @brief plug-in info methods(name, version, SDK version)
        */
        virtual Platform::String^ getPluginVersion() {
            return L"0.0.0";
        }

        virtual Platform::String^ getSDKVersion() {

            return L"0.0.0";
        }

        /**
        @brief switch debug plug-in on/off
        */
        virtual void setDebugMode(bool bDebug) {
            debugMode = bDebug;
        }

        /**
        @brief Start a new session.
        @param appKey The identity of the application.
        */
        virtual void startSession(Platform::String^ appKey) {
            telemetryClient = ref new TelemetryClient();
            telemetryClient->Context->InstrumentationKey = appKey;
        }

        /**
        @brief Stop a session.
        @warning This interface only worked on android
        */
        virtual void stopSession() {
            telemetryClient = nullptr;
            for (auto it = timedEvents.begin(); it != timedEvents.end(); it++) {
                delete it->second;
            }
            timedEvents.clear();
        }

        /**
        @brief Set the timeout for expiring a session.
        @param millis In milliseconds as the unit of time.
        @note It must be invoked before calling startSession.
        */
        virtual void setSessionContinueMillis(int millis) {
        }

        /**
        @brief log an error
        @param errorId The identity of error
        @param message Extern message for the error
        */
        virtual void logError(Platform::String^ errorId, Platform::String^ message) {
            if (telemetryClient == nullptr) {
                return;
            }
            Platform::Collections::Map<Platform::String^, Platform::String^> ^properties = ref new Platform::Collections::Map<Platform::String^, Platform::String^> ;
            properties->Insert(L"message", message);
            telemetryClient->TrackEvent(errorId, properties);
        }

        /**
        @brief log an event.
        @param eventId The identity of event
        @param paramMap Extern parameters of the event, use NULL if not needed.
        */
        virtual void logEvent(Platform::String^ eventId, Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ paramMap) {
            if (telemetryClient == nullptr) {
                return;
            }
            if (paramMap) {
                telemetryClient->TrackEvent(eventId, paramMap);
            }
            else {
                telemetryClient->TrackEvent(eventId);
            }
        }

        /**
        @brief Track an event begin.
        @param eventId The identity of event
        */
        virtual void logTimedEventBegin(Platform::String^ eventId) {
            if (timedEvents.count(eventId)) {
                delete timedEvents[eventId];
            }
            Windows::Foundation::TimeSpan* time = new Windows::Foundation::TimeSpan;
            time->Duration = GetTickCount64() * NANOSECONDS_PER_MILLISECOND;
            OutputDebugString(time->ToString()->Data());
            timedEvents[eventId] = time;
        }

        /**
        @brief Track an event end.
        @param eventId The identity of event
        */
        virtual void logTimedEventEnd(Platform::String^ eventId) {
            if (!timedEvents.count(eventId)) {
                return;
            }
            // calculate time difference
            Windows::Foundation::TimeSpan endTime;
            endTime.Duration = GetTickCount64() * NANOSECONDS_PER_MILLISECOND;
            Windows::Foundation::TimeSpan elapsedTime;
            elapsedTime.Duration = endTime.Duration - timedEvents[eventId]->Duration;
            // send event
            Microsoft::ApplicationInsights::DataContracts::EventTelemetry^ eventTelemetry = ref new Microsoft::ApplicationInsights::DataContracts::EventTelemetry();
            eventTelemetry->Name = eventId;
            eventTelemetry->Metrics->Insert("elapsed_time", elapsedTime.Duration / NANOSECONDS_PER_MILLISECOND);
            telemetryClient->TrackEvent(eventTelemetry);
            delete timedEvents[eventId];
            timedEvents.erase(eventId);
        }

        /**
        @brief Whether to catch uncaught exceptions to server.
        @warning This interface only worked on android.
        */
        virtual void setCaptureUncaughtException(bool enabled) {

        }

        virtual void callFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return;
        }

        virtual Platform::String^ callStringFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return L"";
        }

        virtual int callIntFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return 0;
        }

        virtual bool callBoolFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return false;
        }

        virtual float callFloatFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return 0;
        }
    };
}



