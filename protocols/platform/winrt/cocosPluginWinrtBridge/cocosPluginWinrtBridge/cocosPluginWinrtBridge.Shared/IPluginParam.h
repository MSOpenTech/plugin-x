
#pragma once

namespace cocosPluginWinrtBridge {

    // needs to be kept up to date with the ParamType enum in PluginParam.h
    public enum class ParamTypeEnum {
        kParamTypeNull = 0,
        kParamTypeInt,
		kParamTypeFloat,
		kParamTypeBool,
		kParamTypeString,
        kParamTypeStringMap,
		kParamTypeMap,
    };

    public interface class IPluginParam {
        ParamTypeEnum getCurrentType();
        int getIntValue();
        float getFloatValue();
        bool getBoolValue();
        Platform::String^ getStringValue();
        Windows::Foundation::Collections::IMap<Platform::String^, IPluginParam^>^ getMapValue();
        Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ getStrMapValue();

    };

}
