#include "ProtocolSocial.h"
//#include "ProtocolHelper.h"
#include <stdlib.h>
#include "util.h"

using namespace cocos2d::plugin;
using namespace pluginx;

/**
@brief config the share developer info
@param devInfo This parameter is the info of developer,
different plugin have different format
@warning Must invoke this interface before other interfaces.
And invoked only once.
*/
void ProtocolSocial::configDeveloperInfo(TSocialDeveloperInfo devInfo){

}

/**
* @brief methods of leaderboard feature
*/
void ProtocolSocial::submitScore(const char* leadboardID, long score){

}
void ProtocolSocial::submitScore(const char* leadboardID, long score, ProtocolSocialCallback cb){

}
void ProtocolSocial::showLeaderboard(const char* leaderboardID){

}

/**
* @brief methods of achievement feature
*/
void ProtocolSocial::unlockAchievement(TAchievementInfo achInfo){

}
void ProtocolSocial::unlockAchievement(TAchievementInfo achInfo, ProtocolSocialCallback cb){

}
void ProtocolSocial::showAchievements(){

}
