
#include "ProtocolAds.h"
//#include "ProtocolHelper.h"
#include <stdlib.h>
#include "util.h"

using namespace cocos2d::plugin;
using namespace pluginx;
ProtocolAds::ProtocolAds() {
  _listener = nullptr;
}

ProtocolAds::~ProtocolAds() {
	// TODO should I be deleting this?
  delete _listener;
  _listener = nullptr;
}

void ProtocolAds::configDeveloperInfo(TAdsDeveloperInfo devInfo) {
	//TAdsDeveloperInfoWinRT devInfoWinRT = util::stdStrMapToPlatformStrMap(&devInfo);
	//ProtocolHelper::GlobalCallback->configAdsDeveloperInfo(util::charArrayToPlatformString(const_cast<char*>(getPluginName())), devInfoWinRT);
}

void ProtocolAds::showAds(TAdsInfo info, AdsPos pos){
  //ProtocolHelper::GlobalCallback->showAds(util::charArrayToPlatformString(const_cast<char*>(getPluginName())), (int) info, sizeEnum, (int) pos);
}

void ProtocolAds::hideAds(TAdsInfo type) {
	//ProtocolHelper::GlobalCallback->hideAds(util::charArrayToPlatformString(const_cast<char*>(getPluginName())), (int)type);
}

void ProtocolAds::spendPoints(int points) {
	//ProtocolHelper::GlobalCallback->spendPoints(util::charArrayToPlatformString(const_cast<char*>(getPluginName())), points);
}

//void ProtocolAds::onAdsResult(AdsResultCode code, const char* msg) {
//	if (m_pListener != nullptr) {
//		m_pListener->onAdsResult(code, msg);
//	}
//}

//void ProtocolAds::onPlayerGetPoints(int points) {
//	if (m_pListener != nullptr) {
//		m_pListener->onPlayerGetPoints(this, points);
//	}
//}

