
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

#include "PluginParamWinRT.h"

namespace cocos2d {

    namespace pluginparam {

        void PluginParamWinRT::setCurrentType(cocosPluginWinrtBridge::ParamTypeEnum t) {
            paramType = t;
        }

        void PluginParamWinRT::setIntValue(int val) {
            intValue = val;
        }

        void PluginParamWinRT::setFloatValue(float val) {
            floatValue = val;
        }

        void PluginParamWinRT::setBoolValue(bool val) {
            boolValue = val;
        }

        void PluginParamWinRT::setStringValue(Platform::String^ val) {
            strValue = val;
        }

        void PluginParamWinRT::setMapValue(IMap<Platform::String^, cocosPluginWinrtBridge::IPluginParam^>^ val) {
            mapValue = val;
        }

        void PluginParamWinRT::setStrMapValue(IMap<Platform::String^, Platform::String^>^ val) {
            strMapValue = val;
        }
    }
}