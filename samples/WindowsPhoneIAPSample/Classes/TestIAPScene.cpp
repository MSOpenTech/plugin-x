
#include "TestIAPScene.h"
#include "PluginManager.h"
#include "App.xaml.h"
#include "PluginFactory.h"

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* TestIAP::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TestIAP::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool TestIAP::init() {
    if ( !Layer::init() ) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(TestIAP::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


	MenuItemFont* loadIAPPlugin = MenuItemFont::create("Load plugin", CC_CALLBACK_1(TestIAP::loadPlugin, this));
	MenuItemFont* testPluginPurchase = MenuItemFont::create("Test purchase", CC_CALLBACK_1(TestIAP::runTestPurchase, this));
    MenuItemFont* killPlugin = MenuItemFont::create("Unload plugin", CC_CALLBACK_1(TestIAP::unloadPlugin, this));
    MenuItemFont* getUnfulfilledConsumables = MenuItemFont::create("Query unfulfilled consumables", CC_CALLBACK_1(TestIAP::queryUnfulfilledConsumables, this));
    MenuItemFont* reportFulfillment = MenuItemFont::create("Report fulfillment", CC_CALLBACK_1(TestIAP::reportFulfillment, this));
    MenuItemFont* listingItems = MenuItemFont::create("Get all product IDs", CC_CALLBACK_1(TestIAP::getAllListingItems, this));

	auto testMenu = Menu::create(loadIAPPlugin, testPluginPurchase, killPlugin, getUnfulfilledConsumables, reportFulfillment, listingItems, NULL);
    testMenu->alignItemsVertically();
	testMenu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - (testMenu->getContentSize().height / 2)));
	this->addChild(testMenu, 1);

    label = LabelTTF::create("new session", "Arial", 20);
    label->setPosition(Vec2(visibleSize.width / 2, label->getContentSize().height));
    this->addChild(label, 1);

    this->iap = nullptr;
    return true;
}

void TestIAP::loadPlugin(Ref* pSender) {
    // set up iap
    auto dispatcher = App::GetDispatcher();
    auto factory = plugin::PluginFactory::getInstance();
    factory->setDispatcher(dispatcher);
    // get plugin
	this->iap = dynamic_cast<plugin::ProtocolIAP*>(plugin::PluginManager::getInstance()->loadPlugin("microsoftiap"));
    if (this->iap == nullptr) {
        MessageBox("Failed to load plugin", "Error");
        return;
    }
    iap->setDebugMode(true);
    std::function<void(int, std::string&)> callback = [this](int ret, std::string msg) {
        this->purchaseCallback(ret, msg);
    };
    iap->setCallback(callback);
    // set dev info
	std::map<std::string, std::string> devInfo;
	devInfo["windows_store_proxy"] = "WindowsStoreProxy.xml"; 
	iap->configDeveloperInfo(devInfo);
}

void TestIAP::purchaseCallback(int ret, std::string msg) {
    if (iap == nullptr) {
        MessageBox("plugin not loaded", "Problem");
        return;
    }
    static int counter = 0;
    counter++;
    printf("%s\n", msg.c_str());
    CCLOG("%s", msg.c_str());
    std::string resultText;
    if (ret == plugin::kPaySuccess) {
        resultText = "Success";
    }
    else {
        resultText = "Fail";
    }
    label->setString(resultText);
	MessageBox(msg.c_str(),"Purchase");
}

void TestIAP::runTestPurchase(Ref* pSender) {
    if (iap == nullptr) {
        MessageBox("plugin not loaded", "Problem");
        return;
    }
    // buy product
    std::map < std::string, std::string> productInfo;
    productInfo["product"] = "feature1";
    iap->payForProduct(productInfo);
}

void TestIAP::unloadPlugin(Ref* pSender) {
    plugin::PluginManager::getInstance()->unloadPlugin("microsoftiap");
    this->iap = nullptr;
}

void TestIAP::queryUnfulfilledConsumables(Ref* pSender) {
    if (iap == nullptr) {
        MessageBox("plugin not loaded", "Problem");
        return;
    }
    std::vector<plugin::PluginParam*> params;
    std::string result = iap->callStringFuncWithParam("getUnfulfilledConsumables", params);
    MessageBox(result.c_str(), "unfulfilled consumables result");
}

void TestIAP::reportFulfillment(cocos2d::Ref* pSender) {
    if (iap == nullptr) {
        MessageBox("plugin not loaded", "Problem");
        return;
    }
    std::vector<plugin::PluginParam*> params;
    plugin::PluginParam* productIdParam = new plugin::PluginParam("consumable1");
    plugin::PluginParam* transactionIdParam = new plugin::PluginParam("{00000001-0000-0000-0000-000000000000}");
    params.push_back(productIdParam);
    params.push_back(transactionIdParam);
    bool reportResult = iap->callBoolFuncWithParam("reportConsumableFulfillment", params);
    std::string result = reportResult ? "Success" : "Fail";
    label->setString(result);
    MessageBox(result.c_str(), "unfulfilled consumables result");
}

void TestIAP::getAllListingItems(Ref* pSender) {
    std::vector<plugin::PluginParam*> params;
    std::string productIDs = iap->callStringFuncWithParam("getAllListingItems", params);
    MessageBox(productIDs.c_str(), "productIDs");
}

void TestIAP::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
