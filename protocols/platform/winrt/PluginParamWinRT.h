
#pragma once

#include <collection.h>

#include "PluginParam.h"

using namespace Windows::Foundation::Collections;

namespace pluginparam {

	public ref class PluginParamWinRT sealed : public cocosPluginWinrtBridge::IPluginParam {

    public:
    
        virtual cocosPluginWinrtBridge::ParamTypeEnum getCurrentType() { return paramType; }
        virtual int getIntValue() { return intValue; }
        virtual float getFloatValue() { return floatValue; }
        virtual bool getBoolValue() { return boolValue; }
        virtual Platform::String^ getStringValue() { return strValue; }
        virtual IMap<Platform::String^, cocosPluginWinrtBridge::IPluginParam^>^ getMapValue() { return mapValue; }
        virtual IMap<Platform::String^, Platform::String^>^ getStrMapValue() { return strMapValue; }

        void setCurrentType(cocosPluginWinrtBridge::ParamTypeEnum t);
        void setIntValue(int val);
        void setFloatValue(float val);
        void setBoolValue(bool val);
        void setStringValue(Platform::String^ val);
        void setMapValue(IMap<Platform::String^, cocosPluginWinrtBridge::IPluginParam^>^ val);
        void setStrMapValue(IMap<Platform::String^, Platform::String^>^ val);

    private:
        cocosPluginWinrtBridge::ParamTypeEnum paramType;
        int intValue;
        float floatValue;
        bool boolValue;
        Platform::String^ strValue;
        IMap<Platform::String^, cocosPluginWinrtBridge::IPluginParam^>^ mapValue;
        IMap<Platform::String^, Platform::String^>^ strMapValue;
        
    };

}
