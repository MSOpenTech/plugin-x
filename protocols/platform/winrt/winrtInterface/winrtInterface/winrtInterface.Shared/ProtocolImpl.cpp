#include "pch.h"
#include "IProtocol.h"

using namespace winrtInterface;

namespace winrtInterface {
    public ref class ProtocolImpl sealed : public winrtInterface::IProtocol{
    public:

        virtual Platform::String^ getPluginVersion() {
            return L"";
        }

        virtual Platform::String^ getSDKVersion() {
            return L"";
        };

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
    };
}