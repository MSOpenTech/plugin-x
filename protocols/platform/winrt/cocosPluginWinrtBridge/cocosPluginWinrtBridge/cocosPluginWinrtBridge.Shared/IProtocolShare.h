
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

#include "IProtocol.h"

namespace cocosPluginWinrtBridge {
    
    // this should be kept up to date with the ShareResultCode enum in ProtocolShare.h
    public enum class ShareResultCodeEnum {
        kShareSuccess = 0,
        kShareFail,
        kShareCancel,
        kShareTimeOut
    };

    public delegate void ShareResultHandler(ShareResultCodeEnum ret, Platform::String^ msg);

    public interface class IProtocolShare : IProtocol {
        void configDeveloperInfo(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ devInfo);
        void share(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ info);
        event ShareResultHandler^ OnShareResult;
    };

}
