
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
private:
    PluginMap(){}
};
