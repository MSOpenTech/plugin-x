
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

// Only needed in order to export tne interface classes in winmd, can be 
// deleted if a better way is found.

#include "pch.h"
#include "IPluginParam.h"

using namespace cocosPluginWinrtBridge;

namespace cocosPluginWinrtBridge {
    public ref class PluginParamImpl sealed : public cocosPluginWinrtBridge::IPluginParam{
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