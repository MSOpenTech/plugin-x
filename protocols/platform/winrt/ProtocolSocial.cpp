
#include <stdlib.h>

#include "ProtocolSocial.h"
#include "util.h"
#include "PluginMap.h"

using namespace cocos2d::plugin;
using namespace pluginx;

ProtocolSocial::ProtocolSocial() {
    _listener = nullptr;
    _callback = nullptr; // TODO should these pointers be deleted in the destructor?
}

ProtocolSocial::~ProtocolSocial() {
    PluginMap::mapIProtocol.erase(this);
    PluginMap::mapIProtocolSocial.erase(this);
}

/**
@brief config the share developer info
@param devInfo This parameter is the info of developer,
different plugin have different format
@warning Must invoke this interface before other interfaces.
And invoked only once.
*/
void ProtocolSocial::configDeveloperInfo(TSocialDeveloperInfo devInfo){
    PluginMap::mapIProtocolSocial[this]->configDeveloperInfo(util::stdStrMapToPlatformStrMap(&devInfo));
}

/**
* @brief methods of leaderboard feature
*/
void ProtocolSocial::submitScore(const char* leadboardID, long score){
    Platform::String^ platLeadboardID = pluginx::util::charArrayToPlatformString(leadboardID);
    int64 platScore = score; 
    PluginMap::mapIProtocolSocial[this]->submitScore(platLeadboardID, platScore);
}

void ProtocolSocial::submitScore(const char* leadboardID, long score, ProtocolSocialCallback cb){
    _callback = cb;
    submitScore(leadboardID, score);
}

void ProtocolSocial::showLeaderboard(const char* leaderboardID){
    PluginMap::mapIProtocolSocial[this]->showLeaderBoard(util::charArrayToPlatformString(leaderboardID));
}

/**
* @brief methods of achievement feature
*/
void ProtocolSocial::unlockAchievement(TAchievementInfo achInfo) {
    PluginMap::mapIProtocolSocial[this]->unlockAchievement(util::stdStrMapToPlatformStrMap(&achInfo));
}

void ProtocolSocial::unlockAchievement(TAchievementInfo achInfo, ProtocolSocialCallback cb) {
    _callback = cb;
    unlockAchievement(achInfo);
}

void ProtocolSocial::showAchievements() {
    PluginMap::mapIProtocolSocial[this]->showAchievements();
}
