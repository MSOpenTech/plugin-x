
#pragma once

#include "IProtocol.h"

namespace cocosPluginWinrtBridge {
    
    // needs to be kept up to date with the AdsResultCode inum in ProtocolAds.h
    public enum class AdsResultCodeEnum {
        kAdsReceived = 0,
        kAdsShown,
        kAdsDismissed,
        kPointsSpendSucceed,
        kPointsSpendFailed,
        kNetworkError,
        kUnknownError
    };

    public enum class AdsPosition {
        kPosCenter = 0,
        kPosTop,
        kPosTopLeft,
        kPosTopRight,
        kPosBottom,
        kPosBottomLeft,
        kPosBottomRight
    };

    public delegate void AdsResultHandler(AdsResultCodeEnum result, Platform::String^ msg);
    public delegate void PlayerGetPointsHandler(int points);

    public interface class IProtocolAds : IProtocol {
        void configDeveloperInfo(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ devInfo);
        void showAds(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ info, AdsPosition pos);
        void hideAds(Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^>^ info);
        void queryPoints(); // TODO what does this do?
        void spendPoints(int points);
        event AdsResultHandler^ OnAdsResult;
        event PlayerGetPointsHandler^ OnPlayerGetPoints;
    };

}
