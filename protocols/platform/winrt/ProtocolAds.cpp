
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

#include "ProtocolAds.h"
#include "util.h"
#include "PluginMap.h"

using namespace cocos2d::plugin;
using namespace pluginx;

ProtocolAds::ProtocolAds() {
    _listener = nullptr;
    _callback = nullptr;
}

ProtocolAds::~ProtocolAds() {
    PluginMap::mapIProtocol.erase(this);
    PluginMap::mapIProtocolAds.erase(this);
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
