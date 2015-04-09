
// Only needed in order to export tne interface classes in winmd, can be 
// deleted if a better way is found.

#include "pch.h"
#include "IProtocolAnalytics.h"

using namespace winrtInterface;

namespace winrtInterface {
    public ref class ProtocolAnalyticsImpl sealed : public winrtInterface::IProtocolAnalytics {
    public:

        virtual Platform::String^ getPluginVersion() {
            return L"";
        }

        virtual Platform::String^ getSDKVersion() {
            return L"";
        }

        virtual void setDebugMode(bool bDebug) {
            return;
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

        virtual void startSession(Platform::String^ appkey) {
            return;
        }

        virtual void stopSession() {
            return;
        }

        virtual void setSessionContinueMillis(int millis) {
            return;
        }

        virtual void logError(Platform::String^ errorId, Platform::String^ message) {
            return;
        }

        virtual void logEvent(Platform::String^ eventId, Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ paramMap) {
            return;
        }

        virtual void logTimedEventBegin(Platform::String^ eventId) {
            return;
        }

        virtual void logTimedEventEnd(Platform::String^ eventId) {
            return;
        }

        virtual void setCaptureUncaughtException(bool enabled) {
            return;
        }

    };

}
