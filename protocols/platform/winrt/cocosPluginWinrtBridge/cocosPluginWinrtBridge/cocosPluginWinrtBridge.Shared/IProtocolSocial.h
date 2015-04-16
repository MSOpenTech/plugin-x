
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
    
    // needs to be kept up to date with the SocialRetCode enum in ProtocolSocial.h
    public enum class SocialReturnCode {
        SCORE_SUBMIT_SUCCESS = 1,
        SCORE_SUBMIT_FAILED,
        ACH_UNLOCK_SUCCESS,
        ACH_UNLOCK_FAILED
    };

    public delegate void SocialResultHandler(SocialReturnCode retCode);

    public interface class IProtocolSocial : IProtocol {
        void configDeveloperInfo(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ devInfo);
        void submitScore(Platform::String^ leadboardID, int64 score); // TODO make sure that uint64 is compatible with long type
        void showLeaderBoard(Platform::String^ leaderboardID);
        void unlockAchievement(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ achInfo);
        void showAchievements();
        event SocialResultHandler^ OnSocialResult;
    };

}
