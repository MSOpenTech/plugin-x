
#include "PluginProtocol.h"
#include "util.h"
#include <cstdarg>
#include "winrtInterface_h.h"
#include "PluginMap.h"
using namespace cocos2d::plugin;
using namespace pluginx;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::winrtInterface;
using namespace pluginx::util;
PluginProtocol::~PluginProtocol() {
	// TODO
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
	//Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
	//Vector<PluginParamWinRT^>^ platParams = util::stdVectorToPlatformVector(params);
	//ProtocolHelper::GlobalCallback->callFuncWithParam(util::charArrayToPlatformString(getPluginName()), platFuncName, platParams);
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
  return "";
	//Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
	//Vector<PluginParamWinRT^>^ platParams = util::stdVectorToPlatformVector(params);
	//return util::platformStringToCharArray(ProtocolHelper::GlobalCallback->callStringFuncWithParam(util::charArrayToPlatformString(getPluginName()), platFuncName, platParams));
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
  /*	Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
    Vector<PluginParamWinRT^>^ platParams = util::stdVectorToPlatformVector(params);
    return ProtocolHelper::GlobalCallback->callIntFuncWithParam(util::charArrayToPlatformString(getPluginName()), platFuncName, platParams);
    */ return 0;
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
  /*
	Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
	Vector<PluginParamWinRT^>^ platParams = util::stdVectorToPlatformVector(params);
	return ProtocolHelper::GlobalCallback->callBoolFuncWithParam(util::charArrayToPlatformString(getPluginName()), platFuncName, platParams);
  */
  return 0;
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
  return 0;
  /*
	Platform::String^ platFuncName = util::charArrayToPlatformString(funcName);
	Vector<PluginParamWinRT^>^ platParams = util::stdVectorToPlatformVector(params);
	return ProtocolHelper::GlobalCallback->callFloatFuncWithParam(util::charArrayToPlatformString(getPluginName()), platFuncName, platParams);
  */
}

