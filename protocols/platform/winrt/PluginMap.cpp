
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
