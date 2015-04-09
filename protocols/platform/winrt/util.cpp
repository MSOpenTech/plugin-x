
#include <iostream>

#include "util.h"

using namespace cocos2d::plugin;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace Platform;
using namespace pluginparam;
using namespace Platform::Collections;
using namespace winrtInterface;

namespace pluginx {
    namespace util {

        PluginParamWinRT^ toWinRT(PluginParam* param) {
            PluginParamWinRT^ ret = ref new PluginParamWinRT();
            ret->setCurrentType((ParamTypeEnum)param->getCurrentType());
            if (ret->getCurrentType() == ParamTypeEnum::kParamTypeInt) {
                ret->setIntValue(param->getIntValue());
            }
            else if (ret->getCurrentType() == ParamTypeEnum::kParamTypeFloat) {
                ret->setFloatValue(param->getFloatValue());
            }
            else if (ret->getCurrentType() == ParamTypeEnum::kParamTypeBool) {
                ret->setBoolValue(param->getBoolValue());
            }
            else if (ret->getCurrentType() == ParamTypeEnum::kParamTypeString) {
                ret->setStringValue(stdStringToPlatformString(param->getStringValue()));
            }
            else if (ret->getCurrentType() == ParamTypeEnum::kParamTypeMap) {
                IMap<Platform::String^, int>^ pMap = ref new Platform::Collections::Map<Platform::String^, int>();
                std::map<std::string, PluginParam*>::iterator it;
                for (it = param->getMapValue().begin(); it != param->getMapValue().end(); ++it) {

                }
            }

            return ret;
        }

        Vector<PluginParamWinRT^>^ stdVectorToPlatformVector(std::vector<PluginParam*> vec) {
            Vector<PluginParamWinRT^>^ ret = ref new Vector<PluginParamWinRT^>();
            std::vector<PluginParam*>::iterator it;
            for (it = vec.begin(); it != vec.end(); ++it) {
                ret->Append(toWinRT(*it));
            }
            return ret;
        }

        Platform::Collections::Map<Platform::String^, Platform::String^>^ stdStrMapToPlatformStrMap(std::map<std::string, std::string>* pMap) {
            Platform::Collections::Map<Platform::String^, Platform::String^>^ platMap = ref new Platform::Collections::Map<Platform::String^, Platform::String^>();
            std::map<std::string, std::string>::iterator it;
            for (it = pMap->begin(); it != pMap->end(); ++it) {
                Platform::String^ keyStr = util::stdStringToPlatformString(it->first);
                Platform::String^ valueStr = util::stdStringToPlatformString(it->second);
                // add to collection
                platMap->Insert(keyStr, valueStr);
            }
            return platMap;
        }

        String^ stdStringToPlatformString(std::string str) {
            return ref new String(std::wstring(str.begin(), str.end()).c_str());
        }

        String^ charArrayToPlatformString(const char *str) {
            return stdStringToPlatformString(std::string(str));
        }

        std::string PlatformStringToStdString(String^ str) {
            const wchar_t *w = str->Data();
            std::wstring wstr(w, str->Length());
            return std::string(wstr.begin(), wstr.end());
        }

        // TODO doesn't work, don't use
        const char* PlatformStringToCharArray(String^ str) {
            //const wchar_t *w = str->Data();
            //std::wstring wstr(w, str->Length());
            //return std::string(wstr.begin(), wstr.end()).c_str();
            std::string stdString = PlatformStringToStdString(str);
            const char* charArray = stdString.c_str();
            return charArray;
        }
    } // end namespace util
} // end namespace pluginx
