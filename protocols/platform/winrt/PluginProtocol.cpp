
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

#include <cstdarg>
#include <collection.h>

#include "PluginProtocol.h"
#include "util.h"
#include "PluginMap.h"
#include "PluginParamWinRT.h"

using namespace cocos2d::plugin;
using namespace pluginx;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace cocosPluginWinrtBridge;
using namespace pluginx::util;
using namespace Platform::Collections;
using namespace cocos2d::pluginparam;

PluginProtocol::~PluginProtocol() {
}

std::string PluginProtocol::getPluginVersion() {
  return PlatformStringToStdString(PluginMap::mapIProtocol[this]->getPluginVersion());
}

std::string PluginProtocol::getSDKVersion() {
  return PlatformStringToStdString(PluginMap::mapIProtocol[this]->getSDKVersion());
}

void PluginProtocol::setDebugMode(bool bDebug) {
  PluginMap::mapIProtocol[this]->setDebugMode(bDebug);
}

void PluginProtocol::callFuncWithParam(const char* funcName, PluginParam* param, ...) {
    std::vector<PluginParam*> allParams;
    if (param != NULL) {
        allParams.push_back(param);
        PluginParam* pArg = NULL;
        va_list argp;
        va_start(argp, param);
        while (true) {
            pArg = va_arg(argp, PluginParam*);
            if (pArg == NULL) {
                break;
            }
            allParams.push_back(pArg);
        }
        va_end(argp);
    }
    callFuncWithParam(funcName, allParams);
}

void PluginProtocol::callFuncWithParam(const char* funcName, std::vector<PluginParam*> params) {
    Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
    IVector<IPluginParam^>^ platParams = util::stdVectorToPlatformVector(params);
    PluginMap::mapIProtocol[this]->callFuncWithParam(platFuncName, platParams); 
}

std::string PluginProtocol::callStringFuncWithParam(const char* funcName, PluginParam* param, ...) {
    std::vector<PluginParam*> allParams;
    if (param != NULL) {
        allParams.push_back(param);
        PluginParam* pArg = NULL;
        va_list argp;
        va_start(argp, param);
        while (true) {
            pArg = va_arg(argp, PluginParam*);
            if (pArg == NULL) {
                break;
            }
            allParams.push_back(pArg);
        }
        va_end(argp);
    }
    return callStringFuncWithParam(funcName, allParams);
}

std::string PluginProtocol::callStringFuncWithParam(const char* funcName, std::vector<PluginParam*> params) {
    Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
    Vector<IPluginParam^>^ platParams = util::stdVectorToPlatformVector(params);
    return util::PlatformStringToStdString(PluginMap::mapIProtocol[this]->callStringFuncWithParam(platFuncName, platParams));
}

int PluginProtocol::callIntFuncWithParam(const char* funcName, PluginParam* param, ...) {
    std::vector<PluginParam*> allParams;
    if (param != NULL) {
        allParams.push_back(param);
        PluginParam* pArg = NULL;
        va_list argp;
        va_start(argp, param);
        while (true) {
            pArg = va_arg(argp, PluginParam*);
            if (pArg == NULL) {
                break;
            }
            allParams.push_back(pArg);
        }
        va_end(argp);
    }
    return callIntFuncWithParam(funcName, allParams);
}

int PluginProtocol::callIntFuncWithParam(const char* funcName, std::vector<PluginParam*> params) {
    Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
    Vector<IPluginParam^>^ platParams = util::stdVectorToPlatformVector(params);
    return PluginMap::mapIProtocol[this]->callIntFuncWithParam(platFuncName, platParams);
}

bool PluginProtocol::callBoolFuncWithParam(const char* funcName, PluginParam* param, ...) {
    std::vector<PluginParam*> allParams;
    if (param != NULL) {
        allParams.push_back(param);
        PluginParam* pArg = NULL;
        va_list argp;
        va_start(argp, param);
        while (true) {
            pArg = va_arg(argp, PluginParam*);
            if (pArg == NULL) {
                break;
            }
            allParams.push_back(pArg);
        }
        va_end(argp);
    }
    return callBoolFuncWithParam(funcName, allParams);
}

bool PluginProtocol::callBoolFuncWithParam(const char* funcName, std::vector<PluginParam*> params) {
    Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
    Vector<IPluginParam^>^ platParams = util::stdVectorToPlatformVector(params);
    return PluginMap::mapIProtocol[this]->callBoolFuncWithParam(platFuncName, platParams);
}

float PluginProtocol::callFloatFuncWithParam(const char* funcName, PluginParam* param, ...) {
    std::vector<PluginParam*> allParams;
    if (param != NULL) {
        allParams.push_back(param);
        PluginParam* pArg = NULL;
        va_list argp;
        va_start(argp, param);
        while (true) {
            pArg = va_arg(argp, PluginParam*);
            if (pArg == NULL) {
                break;
            }
            allParams.push_back(pArg);
        }
        va_end(argp);
    }
    return callFloatFuncWithParam(funcName, allParams);
}

float PluginProtocol::callFloatFuncWithParam(const char* funcName, std::vector<PluginParam*> params) {
    Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
    Vector<IPluginParam^>^ platParams = util::stdVectorToPlatformVector(params);
    return PluginMap::mapIProtocol[this]->callFloatFuncWithParam(platFuncName, platParams);
}

