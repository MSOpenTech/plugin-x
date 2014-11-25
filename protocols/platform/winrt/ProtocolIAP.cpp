
#include "ProtocolIAP.h"
//#include "ProtocolHelper.h"
#include "util.h"

using namespace cocos2d::plugin;
using namespace pluginx;

ProtocolIAP::ProtocolIAP() {
  _listener = nullptr;
}

ProtocolIAP::~ProtocolIAP() {
	// TODO
}

void ProtocolIAP::configDeveloperInfo(TIAPDeveloperInfo devInfo) {
	//TIAPDeveloperInfoWinRT devInfoWinRT = util::stdStrMapToPlatformStrMap(&devInfo);
	//ProtocolHelper::GlobalCallback->configIAPDeveloperInfo(util::charArrayToPlatformString(const_cast<char*>(getPluginName())), devInfoWinRT);
}

void ProtocolIAP::payForProduct(TProductInfo info) {
	// TODO
}

void ProtocolIAP::setResultListener(PayResultListener* pListener) {
  _listener = pListener;
}

void onPayResult(PayResultCode ret, const char* msg) {
	// TODO
}