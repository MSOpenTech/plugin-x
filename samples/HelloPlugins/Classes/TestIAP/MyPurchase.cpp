/****************************************************************************
Copyright (c) 2012-2013 cocos2d-x.org

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
#include "MyPurchase.h"
#include "PluginManager.h"
#include "PluginFactory.h"
#include "cocos2d.h"
#include "Configs.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #define PLUGIN_NAME "IAPGooglePlay"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    #define PLUGIN_NAME "microsoftiap"
#endif

using namespace cocos2d::plugin;
using namespace cocos2d;

MyPurchase* MyPurchase::s_pPurchase = NULL;

MyPurchase::MyPurchase()
: s_pRetListener(NULL)
, iapPlugin(NULL)
{

}

MyPurchase::~MyPurchase()
{
	unloadIAPPlugin();
	if (s_pRetListener)
	{
		delete s_pRetListener;
		s_pRetListener = NULL;
	}
}

MyPurchase* MyPurchase::getInstance()
{
	if (s_pPurchase == NULL) {
		s_pPurchase = new MyPurchase();
	}
	return s_pPurchase;
}

void MyPurchase::purgePurchase()
{
	if (s_pPurchase)
	{
		delete s_pPurchase;
		s_pPurchase = NULL;
	}
	PluginManager::end();
}

void MyPurchase::loadIAPPlugin()
{
	if (s_pRetListener == NULL)
	{
		s_pRetListener = new MyPurchaseResult();
	}

    TIAPDeveloperInfo pDevInfo;

	//Google IAP
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	{
		pDevInfo["GooglePlayAppKey"] = GOOGLE_APPKEY;
		if(pDevInfo.empty()) 
        {
			char msg[256] = { 0 };
			sprintf(msg, "Google App Key info is empty. PLZ fill your Google App Key info in %s(nearby line %d)", __FILE__, __LINE__);
			MessageBox(msg, "Google IAP Warning");
		}
	}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    // Windows Store IAP
    {
        auto factory = plugin::PluginFactory::getInstance();
        auto dispatcher = cocos2d::GLViewImpl::sharedOpenGLView()->getDispatcher();
        factory->setDispatcher(dispatcher);
        pDevInfo["windows_store_proxy"] = "WindowsStoreProxy.xml";
    }
#endif
    iapPlugin = dynamic_cast<ProtocolIAP*>(PluginManager::getInstance()->loadPlugin(PLUGIN_NAME));
    iapPlugin->setDebugMode(true);
    iapPlugin->setResultListener(s_pRetListener);
    iapPlugin->configDeveloperInfo(pDevInfo);
}

void MyPurchase::unloadIAPPlugin()
{
	if (iapPlugin)
	{
		PluginManager::getInstance()->unloadPlugin(PLUGIN_NAME);
		iapPlugin = NULL;
	}
}

void MyPurchase::payByMode(TProductInfo info, MyPayMode mode)
{
	ProtocolIAP* pIAP = NULL;
	switch(mode)
	{
	case eGoogle:
		pIAP = iapPlugin;
		break;
	default:
		CCLOG("Unsupported IAP");
		break;
	}

	if (pIAP) {
		pIAP->payForProduct(info);
	}
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

void MyPurchaseResult::onPayResult(PayResultCode ret, const char* msg, TProductInfo info)
{
	char goodInfo[1024] = { 0 };
	sprintf(goodInfo, "ProductID:%s\nPrice:%s\nDesc:%s",
			info.find("IAPId")->second.c_str(),
			info.find("IAPId")->second.c_str(),
			info.find("IAPId")->second.c_str());
	MessageBox(goodInfo , msg);
}

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)

void MyPurchaseResult::onPayResult(PayResultCode ret, const char* msg, TProductInfo info)
{
    std::string title;
    if (ret == PayResultCode::kPaySuccess) {
        title = "Purchase Success";
    }
    else {
        title = "Purchase Fail";
    }
    MessageBox(msg, title.c_str());
}

void MyPurchase::reportConsumablePurchase(char* productId, char* transactionId) {
    plugin::PluginParam productIdParam(productId);
    plugin::PluginParam transactionIdParam(transactionId);
    bool reportResult = iapPlugin->callBoolFuncWithParam("reportConsumableFulfillment", &productIdParam, &transactionIdParam, NULL);
    std::string result = reportResult ? "Success" : "Fail";
    MessageBox(result.c_str(), "consumable fulfillment result");

}
#endif