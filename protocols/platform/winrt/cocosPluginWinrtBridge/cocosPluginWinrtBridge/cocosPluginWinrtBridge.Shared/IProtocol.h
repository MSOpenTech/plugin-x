
#pragma once

#include "IPluginParam.h"

namespace cocosPluginWinrtBridge {

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

}
