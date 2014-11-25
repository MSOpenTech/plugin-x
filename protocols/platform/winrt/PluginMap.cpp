
#include "PluginMap.h"

using namespace cocos2d::plugin;

std::unordered_map<void*, winrtInterface::IProtocol^ > PluginMap::mapIProtocol;
std::unordered_map<void*, winrtInterface::IProtocolAnalytics^ > PluginMap::mapIProtocolAnalytics;

//void PluginMap::addPlugin(st)