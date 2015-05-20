
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

#include <iostream>

#include "util.h"

using namespace cocos2d::plugin;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace Platform;
using namespace cocos2d::pluginparam;
using namespace Platform::Collections;
using namespace cocosPluginWinrtBridge;

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
                IMap<Platform::String^, IPluginParam^>^ pMap = ref new Platform::Collections::Map<Platform::String^, IPluginParam^>();
                std::map<std::string, PluginParam*>::iterator it;
                for (it = param->getMapValue().begin(); it != param->getMapValue().end(); ++it) {
                    pMap->Insert(stdStringToPlatformString(it->first), toWinRT(it->second));
                }
                ret->setMapValue(pMap);
            }
            else if (ret->getCurrentType() == ParamTypeEnum::kParamTypeStringMap) {
                ret->setStrMapValue(stdStrMapToPlatformStrMap(&param->getStrMapValue()));
            }

            return ret;
        }

        Vector<cocosPluginWinrtBridge::IPluginParam^>^ stdVectorToPlatformVector(std::vector<PluginParam*> vec) {
            Vector<cocosPluginWinrtBridge::IPluginParam^>^ ret = ref new Vector<cocosPluginWinrtBridge::IPluginParam^>();
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
