#include "ProtocolSocial.h"
//#include "ProtocolHelper.h"
#include <stdlib.h>
#include "util.h"

using namespace cocos2d::plugin;
using namespace pluginx;

ProtocolSocial::ProtocolSocial() {
  _listener = nullptr;
}

void ProtocolSocial::configDeveloperInfo(TSocialDeveloperInfo devInfo) {
	//ProtocolHelper::GlobalCallback->configSocialDeveloperInfo(util::charArrayToPlatformString(const_cast<char*>(getPluginName())), util::stdStrMapToPlatformStrMap(&devInfo));
}

//void ProtocolSocial::share(TShareInfo info) {
//	ProtocolHelper::GlobalCallback->share(util::charArrayToPlatformString(const_cast<char*>(getPluginName())), util::stdStrMapToPlatformStrMap(&info));
//}

ProtocolSocial::~ProtocolSocial(){
}