
#include "ProtocolIAP.h"
//#include "ProtocolHelper.h"
#include "util.h"
#include "winrtInterface_h.h"
#include "PluginMap.h"

using namespace cocos2d::plugin;
using namespace pluginx;
using namespace winrtInterface;

ProtocolIAP::ProtocolIAP() {
    _listener = nullptr;
}

ProtocolIAP::~ProtocolIAP() {
    // TODO
}

void ProtocolIAP::configDeveloperInfo(TIAPDeveloperInfo devInfo) {
    PluginMap::mapIProtocolIAP[this]->configDeveloperInfo(util::stdStrMapToPlatformStrMap(&devInfo));
}

void ProtocolIAP::payForProduct(TProductInfo info) {
    PluginMap::mapIProtocolIAP[this]->payForProduct(util::stdStrMapToPlatformStrMap(&info));
}

void ProtocolIAP::setResultListener(PayResultListener* pListener) {
    _listener = pListener;
    PluginMap::mapIProtocolIAP[this]->OnPayResult += ref new OnPayResultHandler([this](PayResultCodeEnum ret, Platform::String^ msg) {
        this->onPayResult((PayResultCode)ret, util::PlatformStringToStdString(msg).c_str());
    });
}

void ProtocolIAP::onPayResult(PayResultCode ret, const char* msg) {
    // TODO
    if (_listener != nullptr) {
        std::map<std::string, std::string> empty;
        _listener->onPayResult(ret, msg, empty); // TODO where does the product info come from?
    }
    if (_callback != nullptr) {
        std::string message(msg);
        _callback(ret, message);
    }
}
