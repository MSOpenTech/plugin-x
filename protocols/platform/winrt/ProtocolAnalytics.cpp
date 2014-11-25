
#include "ProtocolAnalytics.h"
#include <stdlib.h>
#include "util.h"
#include "winrtInterface_h.h"
#include "PluginMap.h"
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
using namespace ABI::winrtInterface;
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
