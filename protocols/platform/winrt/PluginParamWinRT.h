
/****************************************************************************
Copyright (c) 2012-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.
Copyright (c) Microsoft Corporation.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#pragma once

#include <collection.h>

#include "PluginParam.h"

using namespace Windows::Foundation::Collections;

namespace cocos2d {

    namespace pluginparam {

        public ref class PluginParamWinRT sealed : public cocosPluginWinrtBridge::IPluginParam{

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
}
