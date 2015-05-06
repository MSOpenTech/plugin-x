
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
#include "TimedEventHelper.h"

#include <unordered_map>
#include <Windows.h>
#include <string>


using namespace cocosPluginWinrtBridge;
using namespace Microsoft::ApplicationInsights;

#define DURATION_LABEL L"duration"
#define ELAPSED_TIME_KEY L"elapsed_time"
#define EVENT_LABEL_KEY L"label"

template <>
struct std::tr1::hash < std::pair<Platform::String^, Platform::String^> > {
    size_t operator()(std::pair<Platform::String^, Platform::String^> x) const throw() {
        return Platform::String::Concat(x.first, x.second)->GetHashCode();
    }
};

namespace microsoftapplicationinsights {

    public ref class microsoftapplicationinsights sealed : public IProtocolAnalytics {
    private:
        std::unordered_map<std::pair<Platform::String^, Platform::String^>, TimedEventHelper^> timedEvents;
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
            logTimedKVEventBegin(eventId, nullptr, nullptr);
        }

        /**
        @brief Track an event end.
        @param eventId The identity of event
        */
        virtual void logTimedEventEnd(Platform::String^ eventId) {
            logTimedKVEventEnd(eventId, nullptr);
        }

        /**
        @brief Whether to catch uncaught exceptions to server.
        @warning This interface only worked on android.
        */
        virtual void setCaptureUncaughtException(bool enabled) {

        }

        virtual void callFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            if (funcName == L"logEventWithDuration") {
                // params[0] = eventId string
                // params[1] = duration int
                logEventWithDuration(params->GetAt(0)->getStringValue(), params->GetAt(1)->getIntValue());
            }
            else if (funcName == L"logEventWithDurationLabel") {
                // params[0] = eventId string
                // params[1] = duration int
                // params[2] = label string
                logEventWithDurationLabel(
                    params->GetAt(0)->getStringValue(),
                    params->GetAt(1)->getIntValue(),
                    params->GetAt(2)->getStringValue());
            }
            else if (funcName == L"logEventWithDurationParams") {
                // params[0] = eventId string
                // params[1] = duration int
                // params[2] = paramMap Map<string, string>
                logEventWithDurationParams(
                    params->GetAt(0)->getStringValue(),
                    params->GetAt(1)->getIntValue(),
                    params->GetAt(2)->getStrMapValue());
            }
            else if (funcName == L"logTimedEventWithLabelBegin") {
                // params[0] = eventId string
                // params[1] = label string
                logTimedEventWithLabelBegin(
                    params->GetAt(0)->getStringValue(),
                    params->GetAt(1)->getStringValue());
            }
            else if (funcName == L"logTimedKVEventBegin") {
                // params[0] = eventId string
                // params[1] = label string
                // params[2] = paramMap Map<string, string>
                logTimedKVEventBegin(
                    params->GetAt(0)->getStringValue(),
                    params->GetAt(1)->getStringValue(),
                    params->GetAt(2)->getStrMapValue());
            }
            else if (funcName == L"logTimedEventBeginWithParams") {
                // params[0] = eventId string
                // params[1] = paramMap Map<string, string>
                logTimedEventBeginWithParams(
                    params->GetAt(0)->getStringValue(),
                    params->GetAt(1)->getStrMapValue());
            }
            else if (funcName == L"logTimedEventWithLabelEnd") {
                // params[0] = eventId string
                // params[1] = label string
                logTimedEventWithLabelEnd(
                    params->GetAt(0)->getStringValue(),
                    params->GetAt(1)->getStringValue());
            }
            else if (funcName == L"logTimedKVEventEnd") {
                // params[0] = eventId string
                // params[1] = label string
                logTimedKVEventEnd(
                    params->GetAt(0)->getStringValue(),
                    params->GetAt(1)->getStringValue());
            }
            else if (funcName == L"logTimedEventEnd") {
                // params[0] = eventId string
                logTimedEventEnd(params->GetAt(0)->getStringValue());
            }
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

    private:
        Platform::String^ intToPlatString(int i) {
            std::string s = std::to_string(i);
            return ref new Platform::String(std::wstring(s.begin(), s.end()).c_str());
        }

        void logEventWithDuration(Platform::String^ eventId, int duration) {
            logEventWithDurationLabel(eventId, duration, DURATION_LABEL);
        }

        void logEventWithDurationLabel(Platform::String^ eventId, int duration, Platform::String^ label) {
            StringMap paramMap = ref new Platform::Collections::Map<Platform::String^, Platform::String^>();
            paramMap->Insert(label, intToPlatString(duration));
            logEvent(eventId, paramMap);
        }

        void logEventWithDurationParams(Platform::String^ eventId, int duration, IStringMap paramMap) {
            paramMap->Insert(DURATION_LABEL, intToPlatString(duration)); 
            logEvent(eventId, paramMap);
        }

        void logTimedEventWithLabelBegin(Platform::String^ eventId, Platform::String^ label) {
            logTimedKVEventBegin(eventId, label, nullptr);
        }

        void logTimedKVEventBegin(Platform::String^ eventId, Platform::String^ label, IStringMap mapData) {
            TimedEventHelper^ timedEventHelper = ref new TimedEventHelper();
            timedEventHelper->startTiming();
            timedEventHelper->setMapData(mapData);
            std::pair<Platform::String^, Platform::String^> key(eventId, label);
            timedEvents[key] = timedEventHelper;
            
        }

        void logTimedEventBeginWithParams(Platform::String^ eventId, IStringMap mapData) {
            logTimedKVEventBegin(eventId, nullptr, mapData);
        }

        void logTimedEventWithLabelEnd(Platform::String^ eventId, Platform::String^ label) {
            logTimedKVEventEnd(eventId, label);
        }

        void logTimedKVEventEnd(Platform::String^ eventId, Platform::String^ label) {
            std::pair<Platform::String^, Platform::String^> key(eventId, label);
            if (!timedEvents.count(key)) {
                return;
            }
            TimedEventHelper^ timedEventHelper = timedEvents[key];
            timedEventHelper->stopTiming();
            // send event
            Microsoft::ApplicationInsights::DataContracts::EventTelemetry^ eventTelemetry = ref new Microsoft::ApplicationInsights::DataContracts::EventTelemetry();
            eventTelemetry->Name = eventId;
            eventTelemetry->Metrics->Insert(ELAPSED_TIME_KEY, timedEventHelper->elapsedTime());
            copyMapData(eventTelemetry, timedEventHelper->getMapData());
            eventTelemetry->Properties->Insert(EVENT_LABEL_KEY, label);
            telemetryClient->TrackEvent(eventTelemetry);
            timedEvents.erase(key);
        }

        void copyMapData(Microsoft::ApplicationInsights::DataContracts::EventTelemetry^ eventTelemetry, IStringMap mapData) {
            if (mapData == nullptr) {
                return;
            }
            typedef Windows::Foundation::Collections::IKeyValuePair<Platform::String^, Platform::String^> T_item;

            Windows::Foundation::Collections::IIterator<T_item^>^ it = (Windows::Foundation::Collections::IIterator<T_item^>^)mapData->First();
            while (it->HasCurrent) {
                T_item^ item = (T_item^)it->Current;
                eventTelemetry->Properties->Insert(item->Key, item->Value);
                it->MoveNext();
            }
        }


    };
}



