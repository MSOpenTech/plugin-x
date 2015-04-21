
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
#include "ProtocolShare.h"
#include "ProtocolUser.h"
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

PluginProtocol* PluginFactory::createPlugin(const char* name) {
	std::wstring suffix;
#if WINAPI_FAMILY==WINAPI_FAMILY_PC_APP
	suffix = L".Windows.dll";
#else
	suffix = L".WindowsPhone.dll";
#endif
	std::wstring wname(name, name + strlen(name));

	HMODULE module = LoadPackagedLibrary((wname + suffix).c_str(), 0);
	if (module == nullptr)
	{
		OutputDebugString(L"Failed to load Plugin ");
		OutputDebugString(wname.c_str());
		return nullptr;
	}
	DllActivationFactoryPtr _DllActivationFactory = (DllActivationFactoryPtr)GetProcAddress(module, "DllGetActivationFactory");
	if (!_DllActivationFactory)
	{
		OutputDebugString(L"Failed to load Plugin ActivationFactory entrypoint");
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
		OutputDebugString(L"Failed to create instance of plugin");
		return nullptr;
	}

    Platform::Object^ base = reinterpret_cast<Platform::Object^>(instance.Get());
    cocosPluginWinrtBridge::IProtocol^ protocol;
    try {
        protocol = safe_cast<IProtocol^>(base);
    }
    catch (Platform::Exception^ e) {
		OutputDebugString(L"Plugin Fails to Implement IProtocol");
		return nullptr;
    }
    // ProtocolIAP
    try {
        cocosPluginWinrtBridge::IProtocolIAP^ iap = safe_cast<IProtocolIAP^>(protocol);
        ProtocolIAP *out = new ProtocolIAP();
        PluginMap::mapIProtocol[out] = iap;
        PluginMap::mapIProtocolIAP[out] = iap;
        iap->setDispatcher(dispatcher);
        // register protocol for plugin event
        iap->OnPayResult += ref new cocosPluginWinrtBridge::OnPayResultHandler([out](cocosPluginWinrtBridge::PayResultCodeEnum ret, Platform::String^ msg) {
            out->onPayResult((PayResultCode)ret, pluginx::util::PlatformStringToStdString(msg).c_str());
        });
        return out;
    }
    catch (Platform::Exception^ e) {
        OutputDebugString(L"Plugin does not implement IProtocolIAP");
    }
    // ProtocolAnalytics
    try {
        cocosPluginWinrtBridge::IProtocolAnalytics^ analytics = safe_cast<IProtocolAnalytics^>(protocol);
        ProtocolAnalytics *out = new ProtocolAnalytics();
        PluginMap::mapIProtocol[out] = analytics;
        PluginMap::mapIProtocolAnalytics[out] = analytics;
        return out;
    }
    catch (Platform::Exception^ e) {
        OutputDebugString(L"Plugin does not implement IProtocolAnalytics");
    }
    // ProtocolSocial
    try {
        cocosPluginWinrtBridge::IProtocolSocial^ social = safe_cast<IProtocolSocial^>(protocol);
        ProtocolSocial* out = new ProtocolSocial();
        PluginMap::mapIProtocol[out] = social;
        PluginMap::mapIProtocolSocial[out] = social;
        // unfortunately the whole function needs to be here because ProtocolSocial doesn't have an OnResult function in its header
        social->OnSocialResult += ref new cocosPluginWinrtBridge::SocialResultHandler([out](cocosPluginWinrtBridge::SocialReturnCode retCode) {
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
    }
    // ProtocolShare
    try {
        cocosPluginWinrtBridge::IProtocolShare^ share = safe_cast<IProtocolShare^>(protocol);
        ProtocolShare* out = new ProtocolShare();
        PluginMap::mapIProtocol[out] = share;
        PluginMap::mapIProtocolShare[out] = share;
        share->OnShareResult += ref new cocosPluginWinrtBridge::ShareResultHandler([out](cocosPluginWinrtBridge::ShareResultCodeEnum ret, Platform::String^ msg) {
            out->onShareResult((ShareResultCode)ret, pluginx::util::PlatformStringToStdString(msg).c_str());
        });
        return out;
    }
    catch (Platform::Exception^ e) {
        OutputDebugString(L"Plugin does not implement IProtocolShare");
    }
    // ProtocolUser
    try {
        cocosPluginWinrtBridge::IProtocolUser^ user = safe_cast<IProtocolUser^>(protocol);
        ProtocolUser* out = new ProtocolUser();
        PluginMap::mapIProtocol[out] = user;
        PluginMap::mapIProtocolUser[out] = user;
        user->OnUserAction += ref new cocosPluginWinrtBridge::UserActionResultHandler([out](cocosPluginWinrtBridge::UserActionResult ret) {
            UserActionResultCode cocosRetCode = (UserActionResultCode)ret;
#pragma warning(suppress: 4996) // getListener is deprecated, but we still need to support it
            UserActionListener* listener = out->getActionListener();
            std::function<void(int, std::string&)> callback = out->getCallback();
            if (listener != nullptr) {
                listener->onActionResult(out, cocosRetCode, ""); // TODO what should the msg be?
            }
            if (callback != nullptr) {
                callback((int)cocosRetCode, std::string("")); // TODO what should the msg be?
            }
        });
    }
    catch (Platform::Exception^ e) {
        OutputDebugString(L"Plugin does not implement IProtocolUser");
    }
    // ProtocolAds
    try {
        cocosPluginWinrtBridge::IProtocolAds^ ads = safe_cast<IProtocolAds^>(protocol);
        ProtocolAds* out = new ProtocolAds();
        PluginMap::mapIProtocol[out] = ads;
        PluginMap::mapIProtocolAds[out] = ads;
        ads->OnAdsResult += ref new cocosPluginWinrtBridge::AdsResultHandler([out](cocosPluginWinrtBridge::AdsResultCodeEnum result, Platform::String^ msg) {
#pragma warning(suppress: 4996) // getListener is deprecated, but we still need to support it
            AdsListener* listener = out->getAdsListener();
            if (listener != nullptr) {
                listener->onAdsResult((AdsResultCode)result, pluginx::util::PlatformStringToCharArray(msg));
            }
            // TODO is the callback field for this callback or the other one?
        });
        ads->OnPlayerGetPoints += ref new cocosPluginWinrtBridge::PlayerGetPointsHandler([out](int points) {
#pragma warning(suppress: 4996) // getListener is deprecated, but we still need to support it
            AdsListener* listener = out->getAdsListener();
            if (listener != nullptr) {
                listener->onPlayerGetPoints(out, points);
            }
            // TODO is the callback field for this callback or the other one?

        });
    }
    catch (Platform::Exception^ e) {
        OutputDebugString(L"Plugin does not implement IProtocolAds");
    }

    OutputDebugString(L"Plugin Fails to Implement any Protocols");
	OutputDebugString(L"Protocol Failed to Load ...");
	return nullptr;
}
