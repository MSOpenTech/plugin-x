
#pragma once

#include <collection.h>

#include "PluginParam.h"

using namespace Windows::Foundation::Collections;

namespace pluginparam {

	public ref class PluginParamWinRT sealed : public winrtInterface::IPluginParam {

    public:
    
        virtual winrtInterface::ParamTypeEnum getCurrentType() { return paramType; }
        virtual int getIntValue() { return intValue; }
        virtual float getFloatValue() { return floatValue; }
        virtual bool getBoolValue() { return boolValue; }
        virtual Platform::String^ getStringValue() { return strValue; }
        virtual IMap<Platform::String^, winrtInterface::IPluginParam^>^ getMapValue() { return mapValue; }
        virtual IMap<Platform::String^, Platform::String^>^ getStrMapValue() { return strMapValue; }

        void setCurrentType(winrtInterface::ParamTypeEnum t);
        void setIntValue(int val);
        void setFloatValue(float val);
        void setBoolValue(bool val);
        void setStringValue(Platform::String^ val);
        void setMapValue(IMap<Platform::String^, winrtInterface::IPluginParam^>^ val);
        void setStrMapValue(IMap<Platform::String^, Platform::String^>^ val);

    private:
        winrtInterface::ParamTypeEnum paramType;
        int intValue;
        float floatValue;
        bool boolValue;
        Platform::String^ strValue;
        IMap<Platform::String^, winrtInterface::IPluginParam^>^ mapValue;
        IMap<Platform::String^, Platform::String^>^ strMapValue;
        
    };

}
