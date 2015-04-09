
#include <vector>
#include <string>
#include <unordered_map>

#include "PluginProtocol.h"
#include "ProtocolAnalytics.h"

class PluginMap {

public:
    void addPlugin(std::string name);
    static std::unordered_map<void*, winrtInterface::IProtocol^ > mapIProtocol;
    static std::unordered_map<void*, winrtInterface::IProtocolAnalytics^ > mapIProtocolAnalytics;
    static std::unordered_map<void*, winrtInterface::IProtocolIAP^ > mapIProtocolIAP;
private:
    PluginMap(){}
};
