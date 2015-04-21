
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

#include "ProtocolUser.h"
#include "PluginMap.h"
#include "util.h"

using namespace cocos2d::plugin;

ProtocolUser::ProtocolUser() {
    _listener = nullptr;
    _callback = nullptr;
}

ProtocolUser::~ProtocolUser() {
    PluginMap::mapIProtocol.erase(this);
    PluginMap::mapIProtocolUser.erase(this);
}

/**
@brief config the application info
@param devInfo This parameter is the info of aplication,
different plugin have different format
@warning Must invoke this interface before other interfaces.
And invoked only once.
*/
void ProtocolUser::configDeveloperInfo(TUserDeveloperInfo devInfo) {
    PluginMap::mapIProtocolUser[this]->configDeveloperInfo(pluginx::util::stdStrMapToPlatformStrMap(&devInfo));
}

/**
@brief User login
*/
void ProtocolUser::login() {
    PluginMap::mapIProtocolUser[this]->login();
}

void ProtocolUser::login(ProtocolUserCallback &cb) {
    _callback = cb;
    login();
}

/**
@brief User logout
*/
void ProtocolUser::logout() {
    PluginMap::mapIProtocolUser[this]->logout();
}

void ProtocolUser::logout(ProtocolUserCallback &cb) {
    _callback = cb;
    logout();
}

bool ProtocolUser::isLoggedIn() {
  return PluginMap::mapIProtocolUser[this]->isLoggedIn();
}

/**
@brief Get session ID
@return If user logined, return value is session ID;
else return value is empty string.
*/
std::string ProtocolUser::getSessionID() {
    Platform::String^ result = PluginMap::mapIProtocolUser[this]->getSessionID();
    return pluginx::util::PlatformStringToStdString(result);
}

/**
@brief get Access Token
*/
std::string ProtocolUser::getAccessToken() {
    Platform::String^ result = PluginMap::mapIProtocolUser[this]->getAccessToken();
    return pluginx::util::PlatformStringToStdString(result);
}






