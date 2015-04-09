
// Only needed in order to export tne interface classes in winmd, can be 
// deleted if a better way is found.

#include "pch.h"
#include "IProtocolIAP.h"

using namespace cocosPluginWinrtBridge;

namespace cocosPluginWinrtBridge {
    public ref class ProtocolIAPImpl sealed : public cocosPluginWinrtBridge::IProtocolIAP {
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

        virtual void configDeveloperInfo(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ devInfo) {
            return;
        }

        virtual void payForProduct(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ info) {
            return;
        }
        
        virtual void setDispatcher(Windows::UI::Core::CoreDispatcher^ dispatcher) {
            return;
        }

        virtual event OnPayResultHandler^ OnPayResult;
    };

}

