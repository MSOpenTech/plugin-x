
#include <stdlib.h>

#include "ProtocolAds.h"
#include "util.h"
#include "PluginMap.h"

using namespace cocos2d::plugin;
using namespace pluginx;

ProtocolAds::ProtocolAds() {
    _listener = nullptr;
}

ProtocolAds::~ProtocolAds() {
    PluginMap::mapIProtocol.erase(this);
    PluginMap::mapIProtocolAds.erase(this);
	// TODO should I be deleting this?
    delete _listener;
    _listener = nullptr;
}

void ProtocolAds::configDeveloperInfo(TAdsDeveloperInfo devInfo) {
    PluginMap::mapIProtocolAds[this]->configDeveloperInfo(pluginx::util::stdStrMapToPlatformStrMap(&devInfo));
}

void ProtocolAds::showAds(TAdsInfo info, AdsPos pos){
    PluginMap::mapIProtocolAds[this]->showAds(pluginx::util::stdStrMapToPlatformStrMap(&info), (cocosPluginWinrtBridge::AdsPosition)pos);
}

void ProtocolAds::hideAds(TAdsInfo type) {
    PluginMap::mapIProtocolAds[this]->hideAds(pluginx::util::stdStrMapToPlatformStrMap(&type));
}

void ProtocolAds::spendPoints(int points) {
    PluginMap::mapIProtocolAds[this]->spendPoints(points);
}
