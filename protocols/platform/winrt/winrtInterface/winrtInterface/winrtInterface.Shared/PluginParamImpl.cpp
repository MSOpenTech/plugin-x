
// Only needed in order to export tne interface classes in winmd, can be 
// deleted if a better way is found.

#include "pch.h"
#include "IPluginParam.h"

using namespace winrtInterface;

namespace winrtInterface {
    public ref class PluginParamImpl sealed : public winrtInterface::IPluginParam{
    public:
        
        virtual ParamTypeEnum getCurrentType() {
            return ParamTypeEnum::kParamTypeNull;
        }
        virtual int getIntValue() {
            return 0;
        }

        virtual float getFloatValue() {
            return 0;
        }

        virtual bool getBoolValue() {
            return false;
        }

        virtual Platform::String^ getStringValue() {
            return L"";
        }

        virtual Windows::Foundation::Collections::IMap<Platform::String^, IPluginParam^>^ getMapValue() {
            return ref new Platform::Collections::Map <Platform::String^, IPluginParam^> ;
        }

        virtual Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ getStrMapValue() {
            return ref new Platform::Collections::Map <Platform::String^, Platform::String^> ;
        }
    };
}