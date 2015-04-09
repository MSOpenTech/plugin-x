#pragma once


namespace winrtInterface {

    public interface class IPluginParam {
        int getCurrentType();
    };

    public interface class IProtocol {
        Platform::String^ getPluginVersion();
        Platform::String^ getSDKVersion();
        void setDebugMode(bool bDebug);
        void callFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params); 
        Platform::String^ callStringFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params); 
        int callIntFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params); 
        bool callBoolFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params); 
        float callFloatFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params); 
    };

    public interface class IProtocolAnalytics : IProtocol {
        void startSession(Platform::String^ appkey);
        void stopSession();
        void setSessionContinueMillis(int millis);
        void logError(Platform::String^ errorId, Platform::String^ message);
        void logEvent(Platform::String^ eventId, Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ paramMap);
        void logTimedEventBegin(Platform::String^ eventId);
        void logTimedEventEnd(Platform::String^ eventId);
        void setCaptureUncaughtException(bool enabled);
    };

}
