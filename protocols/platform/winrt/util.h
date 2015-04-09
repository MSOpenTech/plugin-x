
#pragma once

#include <string>
#include <algorithm>
#include <collection.h>
#include <wrl\wrappers\corewrappers.h>

#include "PluginParam.h"
#include "ProtocolAnalytics.h"
#include "PluginProtocol.h"
#include "PluginParamWinRT.h"

namespace pluginx {
    namespace util {
        Platform::String^ charArrayToPlatformString(const char* chStr);
        Platform::String^ stdStringToPlatformString(const std::string str);
        pluginparam::PluginParamWinRT^ toWinRT(cocos2d::plugin::PluginParam* param);
        Platform::Collections::Vector<pluginparam::PluginParamWinRT^>^ stdVectorToPlatformVector(std::vector<cocos2d::plugin::PluginParam*> vec);
        const char* PlatformStringToCharArray(Platform::String^);
        std::string PlatformStringToStdString(Platform::String^);
        Platform::Collections::Map<Platform::String^, Platform::String^>^ stdStrMapToPlatformStrMap(std::map<std::string, std::string>* pMap);
    }
}
