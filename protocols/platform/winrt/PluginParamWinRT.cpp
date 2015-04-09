
#include "PluginParamWinRT.h"

namespace pluginparam {

    
    /*
	int PluginParamWinRT::getCurrentType() {
		return paramType;
	}
    */
    

	int PluginParamWinRT::getIntValue() {
		return intValue;
	}

	float PluginParamWinRT::getFloatValue() {
		return floatValue;
	}

	bool PluginParamWinRT::getBoolValue() {
		return boolValue;
	}

	Platform::String^ PluginParamWinRT::getStringValue() {
		return strValue;
	}

	IMap<Platform::String^, int>^ PluginParamWinRT::getMapValue() {
		return mapValue;
	}

	IMap<Platform::String^, Platform::String^>^ PluginParamWinRT::getStrMapValue() {
		return strMapValue;
	}

	void PluginParamWinRT::setCurrentType(int t) {
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

	void PluginParamWinRT::setMapValue(IMap<Platform::String^, int>^ val) {
		mapValue = val;
	}

	void PluginParamWinRT::setStrMapValue(IMap<Platform::String^, Platform::String^>^ val) {
		strMapValue = val;
	}
}