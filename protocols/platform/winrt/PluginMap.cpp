
#include "PluginMap.h"

using namespace cocos2d::plugin;

std::unordered_map<void*, cocosPluginWinrtBridge::IProtocol^ > PluginMap::mapIProtocol;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolAnalytics^ > PluginMap::mapIProtocolAnalytics;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolIAP^ > mapIProtocolIAP;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolSocial^ > PluginMap::mapIProtocolSocial;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolShare^ > PluginMap::mapIProtocolShare;

//void PluginMap::addPlugin(st)
