
#pragma once
#include <string>
#include <algorithm>
#include "PluginParam.h"
#include "ProtocolAnalytics.h"
#include "PluginProtocol.h"
#include <wrl\wrappers\corewrappers.h>
#include "winrtInterface_h.h"
namespace pluginx {
	namespace util {
    Platform::String^ charArrayToPlatformString(const char* chStr);
    Platform::String^ stdStringToPlatformString(const std::string str);
		//PluginParamWinRT^ toWinRT(cocos2d::plugin::PluginParam* param);
		//Platform::Collections::Vector<PluginParamWinRT^>^ stdVectorToPlatformVector(std::vector<cocos2d::plugin::PluginParam*> vec);
    const char* PlatformStringToCharArray(Platform::String^);
    std::string PlatformStringToStdString(Platform::String^);
		//Platform::Collections::Map<Platform::String^, Platform::String^>^ stdStrMapToPlatformStrMap(std::map<std::string, std::string>* pMap);
    
  }
}