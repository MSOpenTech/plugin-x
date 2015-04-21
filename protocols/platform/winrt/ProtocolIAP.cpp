
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
