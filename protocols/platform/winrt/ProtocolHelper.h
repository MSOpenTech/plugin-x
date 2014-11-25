#pragma once

#include "IProtocolCallback.h"
#include "IPluginMapCallback.h"

namespace plugin_x {
	public ref class ProtocolHelper sealed {
	public:
		ProtocolHelper() {};
		property static IProtocolCallback^ GlobalCallback;
		property static IPluginMapCallback^ mapCallback;
		static void SetCallback(IProtocolCallback^ callback) { ProtocolHelper::GlobalCallback = callback; }
		static void SetPluginMapCallback(IPluginMapCallback^ callback) { ProtocolHelper::mapCallback = callback; }
	};
}