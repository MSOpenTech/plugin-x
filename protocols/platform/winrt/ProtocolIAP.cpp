
#include "ProtocolIAP.h"
#include "util.h"
#include "PluginMap.h"

using namespace cocos2d::plugin;
using namespace pluginx;
using namespace cocosPluginWinrtBridge;

ProtocolIAP::ProtocolIAP() {
    _listener = nullptr;
    _callback = nullptr;
}

ProtocolIAP::~ProtocolIAP() {
    PluginMap::mapIProtocol.erase(this);
    PluginMap::mapIProtocolIAP.erase(this);
}

void ProtocolIAP::configDeveloperInfo(TIAPDeveloperInfo devInfo) {
    PluginMap::mapIProtocolIAP[this]->configDeveloperInfo(util::stdStrMapToPlatformStrMap(&devInfo));
}

void ProtocolIAP::payForProduct(TProductInfo info) {
    PluginMap::mapIProtocolIAP[this]->payForProduct(util::stdStrMapToPlatformStrMap(&info));
}

void ProtocolIAP::payForProduct(TProductInfo info, ProtocolIAPCallback cb) {
    _callback = cb;
    payForProduct(info);
}

void ProtocolIAP::setResultListener(PayResultListener* pListener) {
    _listener = pListener;
}

void ProtocolIAP::onPayResult(PayResultCode ret, const char* msg) {
    if (_listener != nullptr) {
        std::map<std::string, std::string> empty;
        _listener->onPayResult(ret, msg, empty); // TODO where does the product info come from?
    }
    if (_callback != nullptr) {
        std::string message(msg);
        _callback(ret, message);
    }
}
