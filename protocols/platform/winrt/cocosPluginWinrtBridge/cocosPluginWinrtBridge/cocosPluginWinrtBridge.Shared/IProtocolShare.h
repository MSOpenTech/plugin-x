
#pragma once

#include "IProtocol.h"

namespace cocosPluginWinrtBridge {
    
    // this should be kept up to date with the ShareResultCode enum in ProtocolShare.h
    public enum class ShareResultCodeEnum {
        kShareSuccess = 0,
        kShareFail,
        kShareCancel,
        kShareTimeOut
    };

    public delegate void ShareResultHandler(ShareResultCodeEnum ret, Platform::String^ msg);

    public interface class IProtocolShare : IProtocol {
        void configDeveloperInfo(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ devInfo);
        void share(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ info);
        event ShareResultHandler^ OnShareResult;
    };

}
