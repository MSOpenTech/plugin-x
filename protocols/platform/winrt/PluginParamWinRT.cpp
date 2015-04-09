
#include "PluginParamWinRT.h"

namespace pluginparam {

	void PluginParamWinRT::setCurrentType(winrtInterface::ParamTypeEnum t) {
		paramType = t;
	}

	void PluginParamWinRT::setIntValue(int val) {
		intValue = val;
	}

	void PluginParamWinRT::setFloatValue(float val) {
		floatValue = val;
	}

	void PluginParamWinRT::setBoolValue(bool val) {
		boolValue = val;
	}

	void PluginParamWinRT::setStringValue(Platform::String^ val) {
		strValue = val;
	}

	void PluginParamWinRT::setMapValue(IMap<Platform::String^, winrtInterface::IPluginParam^>^ val) {
		mapValue = val;
	}

	void PluginParamWinRT::setStrMapValue(IMap<Platform::String^, Platform::String^>^ val) {
		strMapValue = val;
	}
}