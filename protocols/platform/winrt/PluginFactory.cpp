
#include <stdlib.h>
#include <string>
#include <Windows.Foundation.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>

#include "PluginFactory.h"
#include "PluginProtocol.h"
#include "ProtocolAds.h"
#include "ProtocolAnalytics.h"
#include "ProtocolIAP.h"
#include "ProtocolSocial.h"
#include "PluginMap.h"
#include "util.h"

using namespace cocos2d::plugin;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace cocosPluginWinrtBridge;

typedef HRESULT(WINAPI *DllActivationFactoryPtr)(HSTRING, IActivationFactory **);

static PluginFactory* s_pFactory;

PluginFactory::PluginFactory() {
}

PluginFactory::~PluginFactory() {
}

void PluginFactory::setDispatcher(Windows::UI::Core::CoreDispatcher^ d) {
    dispatcher = d;
}

PluginFactory* PluginFactory::getInstance() {
	if (s_pFactory == nullptr) {
		s_pFactory = new PluginFactory();
	}
	return s_pFactory;
}

void PluginFactory::purgeFactory() {
	if (s_pFactory != nullptr) {
		delete s_pFactory;
		s_pFactory = nullptr;
	}
}

// TODO should return correct protocol object
PluginProtocol* PluginFactory::createPlugin(const char* name) {
	//ComPtr<IProtocol> Protocol;
	std::wstring suffix;
#if WINAPI_FAMILY==WINAPI_FAMILY_PC_APP
	suffix = L".Windows.dll";
#else
	suffix = L".WindowsPhone.dll";
#endif
	std::wstring wname(name, name + strlen(name));

    //Microsoft::WRL::Details::ComPtrRef<IProtocol> plugin = Windows::Foundation::ActivateInstance(wname + suffix);
	HMODULE module = LoadPackagedLibrary((wname + suffix).c_str(), 0);
	if (module == nullptr)
	{
		OutputDebugStringA("Failed to load Plugin ");
		OutputDebugStringA(name);
		return nullptr;
	}
	DllActivationFactoryPtr _DllActivationFactory = (DllActivationFactoryPtr)GetProcAddress(module, "DllGetActivationFactory");
	if (!_DllActivationFactory)
	{
		OutputDebugStringA("Failed to load Plugin ActivationFactory entrypoint");
		return nullptr;
	}

	HString Plugin, PluginAnalytics;
	Plugin.Set((wname + L"." + wname).c_str());
	ComPtr<IActivationFactory>factoryPlugin;
	_DllActivationFactory(Plugin.Get(), factoryPlugin.GetAddressOf());

	if (factoryPlugin.Get() == nullptr)
	{
		OutputDebugStringW((L"Plugin failed to implement class " + wname + L"." + wname).c_str());
		return nullptr;
	}
	ComPtr<IInspectable> instance;
	factoryPlugin.Get()->ActivateInstance(instance.GetAddressOf());
	if (instance.Get() == nullptr)
	{
		OutputDebugStringA("Failed to create instance of plugin");
		return nullptr;
	}

    Platform::Object^ base = reinterpret_cast<Platform::Object^>(instance.Get());
    cocosPluginWinrtBridge::IProtocol^ protocol;
    try {
        protocol = safe_cast<IProtocol^>(base);
    }
    catch (Platform::Exception^ e) {
		OutputDebugStringA("Plugin Fails to Implement IProtocol");
		return nullptr;
    }
    // ProtocolIAP
    try {
        cocosPluginWinrtBridge::IProtocolIAP^ iap = safe_cast<IProtocolIAP^>(protocol);
        ProtocolIAP *out = new ProtocolIAP();
        PluginMap::mapIProtocol[out] = iap;
        PluginMap::mapIProtocolIAP[out] = dynamic_cast<cocosPluginWinrtBridge::IProtocolIAP^>(PluginMap::mapIProtocol[out]);
        iap->setDispatcher(dispatcher);
        // register protocol for plugin event
        PluginMap::mapIProtocolIAP[out]->OnPayResult += ref new cocosPluginWinrtBridge::OnPayResultHandler([out](cocosPluginWinrtBridge::PayResultCodeEnum ret, Platform::String^ msg) {
            out->onPayResult((PayResultCode)ret, pluginx::util::PlatformStringToStdString(msg).c_str());
        });
        return out;
    }
    catch (Platform::Exception^ e) {
        OutputDebugString(L"Plugin does not implement IProtocolIAP");
    }
    // ProtocolAnalytics
    try {
        auto analytics = safe_cast<IProtocolAnalytics^>(protocol);
        ProtocolAnalytics *out = new ProtocolAnalytics();
        PluginMap::mapIProtocol[out] = analytics;
        PluginMap::mapIProtocolAnalytics[out] = dynamic_cast<cocosPluginWinrtBridge::IProtocolAnalytics^>(PluginMap::mapIProtocol[out]);
        return out;
    }
    catch (Platform::Exception^ e) {
        OutputDebugString(L"Plugin does not implement IProtocolAnalytics");
        return nullptr;
    }
    // ProtocolSocial
    try {
        auto social = safe_cast<IProtocolSocial^>(protocol);
        ProtocolSocial* out = new ProtocolSocial();
        PluginMap::mapIProtocol[out] = social;
        PluginMap::mapIProtocolSocial[out] = dynamic_cast<cocosPluginWinrtBridge::IProtocolSocial^>(PluginMap::mapIProtocol[out]);
        // TODO set up event listeners here
        // unfortunately the whole function needs to be here because ProtocolSocial doesn't have an OnResult function in its header
        PluginMap::mapIProtocolSocial[out]->OnSocialResult += ref new cocosPluginWinrtBridge::SocialResultHandler([out](cocosPluginWinrtBridge::SocialReturnCode retCode) {
            SocialRetCode cocosRetCode = (SocialRetCode)retCode;
#pragma warning(suppress: 4996) // getListener is deprecated, but we still need to support it
            SocialListener* listener = out->getListener();
            std::function<void(int, std::string&)> callback = out->getCallback();
            if (listener != nullptr) {
                listener->onSocialResult(cocosRetCode, ""); // TODO what should the msg be?
            }
            if (callback != nullptr) {
                callback((int)cocosRetCode, std::string("")); // TODO what should the msg be?
            }
        });
        return out;
    }
    catch (Platform::Exception^ e) {
        OutputDebugString(L"Plugin does not implement IProtocolSocial");
        return nullptr;
    }

    // TODO add other protocols here
    OutputDebugStringA("Plugin Fails to Implement any Protocols");
	OutputDebugStringA("Protocol Failed to Load ...");
	return nullptr;
}
