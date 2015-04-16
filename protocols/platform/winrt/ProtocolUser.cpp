
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






