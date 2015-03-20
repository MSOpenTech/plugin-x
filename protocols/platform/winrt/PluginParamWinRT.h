
#pragma once

#include <collection.h>

#include "winrtInterface_h.h"
#include "PluginParam.h"

using namespace Windows::Foundation::Collections;

namespace pluginparam {

	public ref class PluginParamWinRT sealed : public winrtInterface::IPluginParam {

        static const int PARAMTYPE_NULL = 0;
        static const int PARAMTYPE_INT = 1;
        static const int PARAMTYPE_FLOAT = 2;
        static const int PARAMTYPE_BOOL = 3;
        static const int PARAMTYPE_STRING = 4;
        static const int PARAMTYPE_STRINGMAP = 5;
        static const int PARAMTYPE_MAP = 6;

    public:
    
        int getCurrentType();
        int getIntValue();
        float getFloatValue();
        bool getBoolValue();
        Platform::String^ getStringValue();
        IMap<Platform::String^, int>^ getMapValue();
        IMap<Platform::String^, Platform::String^>^ getStrMapValue();

        void setCurrentType(int t);
        void setIntValue(int val);
        void setFloatValue(float val);
        void setBoolValue(bool val);
        void setStringValue(Platform::String^ val);
        void setMapValue(IMap<Platform::String^, int>^ val);
        void setStrMapValue(IMap<Platform::String^, Platform::String^>^ val);

    private:
        int paramType;
        int intValue;
        float floatValue;
        bool boolValue;
        Platform::String^ strValue;
        IMap<Platform::String^, int>^ mapValue;
        IMap<Platform::String^, Platform::String^>^ strMapValue;
        
    };
}
