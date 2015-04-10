
#pragma once

#include "IProtocol.h"

namespace cocosPluginWinrtBridge {
    
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
