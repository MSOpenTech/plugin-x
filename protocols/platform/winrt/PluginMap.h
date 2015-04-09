
#include <vector>
#include <string>
#include <unordered_map>

#include "PluginProtocol.h"
#include "ProtocolAnalytics.h"

class PluginMap {

public:
    void addPlugin(std::string name);
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocol^ > mapIProtocol;
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolAnalytics^ > mapIProtocolAnalytics;
    static std::unordered_map<void*, cocosPluginWinrtBridge::IProtocolIAP^ > mapIProtocolIAP;
private:
    PluginMap(){}
};
