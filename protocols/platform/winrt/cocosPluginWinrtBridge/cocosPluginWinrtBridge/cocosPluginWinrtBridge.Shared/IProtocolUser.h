
#pragma once

#include "IProtocol.h"

namespace cocosPluginWinrtBridge {
    
    public enum class UserActionResult {
        kLoginSucceed = 0,
        kLoginFailed,
        kLogoutSucceed
    };

    public delegate void UserActionResultHandler(UserActionResult ret);

    public interface class IProtocolUser : IProtocol {
        void configDeveloperInfo(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ devInfo);
        void login();
        void logout();
        bool isLoggedIn();
        Platform::String^ getSessionID();
        Platform::String^ getAccessToken();
        event UserActionResultHandler^ OnUserAction;
    };

}