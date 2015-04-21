
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
#include <wrl.h>
#include <wrl\event.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\implements.h>
#include <wrl\internal.h>
#include <wrl\module.h>
#include <wrl\async.h>
#include <windows.foundation.h>
#include <windows.foundation.collections.h>
#include <wrl\implements.h>
#include <collection.h>

#include "ProtocolAnalytics.h"
#include "util.h"
#include "PluginMap.h"

using namespace cocosPluginWinrtBridge;
using namespace cocos2d::plugin;
using namespace pluginx;
using namespace Microsoft::WRL;
using namespace pluginx::util;
using namespace ABI::Windows::Foundation::Collections;
using namespace Platform::Collections;
using namespace Platform;

ProtocolAnalytics::ProtocolAnalytics() {

}

ProtocolAnalytics::~ProtocolAnalytics() {
    PluginMap::mapIProtocol.erase(this);
    PluginMap::mapIProtocolAnalytics.erase(this);
}

void ProtocolAnalytics::startSession(const char* appKey) {
  PluginMap::mapIProtocolAnalytics[this]->startSession(charArrayToPlatformString(appKey));
}

void ProtocolAnalytics::stopSession() {
  PluginMap::mapIProtocolAnalytics[this]->stopSession();
}

void ProtocolAnalytics::setSessionContinueMillis(long millis) {
  PluginMap::mapIProtocolAnalytics[this]->setSessionContinueMillis(millis);
}

void ProtocolAnalytics::logError(const char* errorId, const char* message) {
  PluginMap::mapIProtocolAnalytics[this]->logError(charArrayToPlatformString(errorId), charArrayToPlatformString(message));
}

void ProtocolAnalytics::logEvent(const char* eventId, LogEventParamMap* paramMap) {
  if (paramMap)
  {
    Map<String^,String^> ^pMap = ref new Map<String^, String^>();
    for (auto pair : *paramMap)
    {
      pMap->Insert(stdStringToPlatformString(pair.first), stdStringToPlatformString(pair.second));
    }
    PluginMap::mapIProtocolAnalytics[this]->logEvent(util::charArrayToPlatformString(eventId), pMap);
    return;
  }
  
  PluginMap::mapIProtocolAnalytics[this]->logEvent(util::charArrayToPlatformString(eventId), nullptr);
}

void ProtocolAnalytics::logTimedEventBegin(const char* eventId) {
  PluginMap::mapIProtocolAnalytics[this]->logTimedEventBegin(charArrayToPlatformString(eventId));
}

void ProtocolAnalytics::logTimedEventEnd(const char* eventId) {
  PluginMap::mapIProtocolAnalytics[this]->logTimedEventEnd(charArrayToPlatformString(eventId));
}

void ProtocolAnalytics::setCaptureUncaughtException(bool enabled) {
  PluginMap::mapIProtocolAnalytics[this]->setCaptureUncaughtException(enabled);
}
