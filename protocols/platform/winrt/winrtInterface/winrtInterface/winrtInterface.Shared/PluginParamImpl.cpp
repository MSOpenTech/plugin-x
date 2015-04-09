#include "pch.h"
#include "IProtocol.h"

using namespace winrtInterface;

namespace winrtInterface {
    public ref class PluginParamImpl sealed : public winrtInterface::IPluginParam{
    public:
        
        virtual int getCurrentType() {
            return 0;
        }
    };
}