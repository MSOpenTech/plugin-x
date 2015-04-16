
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

#include <stdlib.h>

#include "ProtocolSocial.h"
#include "util.h"
#include "PluginMap.h"

using namespace cocos2d::plugin;
using namespace pluginx;

ProtocolSocial::ProtocolSocial() {
    _listener = nullptr;
    _callback = nullptr;
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
