
#pragma once

#include "IProtocol.h"

namespace winrtInterface {

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