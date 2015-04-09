
#pragma once

namespace cocosPluginWinrtBridge {

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
