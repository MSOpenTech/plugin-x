#pragma once

#include "IProtocol.h"

namespace cocosPluginWinrtBridge {
    
    // needs to be kept up to date with the PayResultCode enum in ProtocolIAP.h
    public enum class PayResultCodeEnum {
        kPaySuccess = 0,
        kPayFail,
        kPayCancel,
        kPayTimeOut
    };

    public delegate void OnPayResultHandler(PayResultCodeEnum ret, Platform::String^ msg);

    public interface class IProtocolIAP : IProtocol {
        void configDeveloperInfo(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ devInfo);
        void payForProduct(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ info);
        void setDispatcher(Windows::UI::Core::CoreDispatcher^ dispatcher);
        event OnPayResultHandler^ OnPayResult;
    };

}