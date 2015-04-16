
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

#include <vector>
#include <string>
#include <unordered_map>

#include "PluginProtocol.h"

class PluginMap {

public:
    void addPlugin(std::string name);
    // TODO should all of the void* be changed to their correct types? we know them
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocol^ > mapIProtocol;
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolAnalytics^ > mapIProtocolAnalytics;
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolIAP^ > mapIProtocolIAP;
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolSocial^ > mapIProtocolSocial;
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolShare^ > mapIProtocolShare;
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolUser^ > mapIProtocolUser;
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolAds^ > mapIProtocolAds;
private:
    PluginMap(){}
};
