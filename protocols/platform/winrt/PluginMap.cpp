
#include "PluginMap.h"

using namespace cocos2d::plugin;

std::unordered_map<void*, cocosPluginWinrtBridge::IProtocol^ > PluginMap::mapIProtocol;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolAnalytics^ > PluginMap::mapIProtocolAnalytics;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolIAP^ > PluginMap::mapIProtocolIAP;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolSocial^ > PluginMap::mapIProtocolSocial;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolShare^ > PluginMap::mapIProtocolShare;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolUser^ > PluginMap::mapIProtocolUser;
std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolAds^ > PluginMap::mapIProtocolAds;

//void PluginMap::addPlugin(st)
