
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
#include "IProtocolAds.h"

using namespace cocosPluginWinrtBridge;

namespace cocosPluginWinrtBridge {
    public ref class ProtocolAdsImpl sealed : public cocosPluginWinrtBridge::IProtocolAds {
    public:

        virtual Platform::String^ getPluginVersion() {
            return L"";
        }

        virtual Platform::String^ getSDKVersion() {
            return L"";
        }

        virtual void setDebugMode(bool bDebug) {
            return;
        }

        virtual void callFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return;
        }

        virtual Platform::String^ callStringFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return L"";
        }

        virtual int callIntFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return 0;
        }

        virtual bool callBoolFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return false;
        }

        virtual float callFloatFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return 0;
        }

        virtual void configDeveloperInfo(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ devInfo) {
            return;
        }

        virtual void showAds(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ info, AdsPosition pos) {
            return;
        }

        virtual void hideAds(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ info) {
            return;
        }

        virtual void queryPoints() { 
            return;
        }

        virtual void spendPoints(int points) {
            return;
        }

        virtual event AdsResultHandler^ OnAdsResult;

        virtual event PlayerGetPointsHandler^ OnPlayerGetPoints;


    };

}
