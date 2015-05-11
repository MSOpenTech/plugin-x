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
#include "TestIAPScene.h"
#include "PluginManager.h"
#include "AppDelegate.h"
#include "MyPurchase.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocos2d::plugin;
using namespace cocos2d::ui;

Scene* TestIAP::scene()
{
    Scene *scene = Scene::create();
    TestIAP *layer = TestIAP::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool TestIAP::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    //Load plugins
    MyPurchase::getInstance()->loadIAPPlugin();

    Size winSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Back button
    auto backButton = Button::create("btn_normal.png","btn_pressed.png");
    backButton->setAnchorPoint(Vec2(1, 0));
    backButton->setTitleText("Back");
    backButton->setScale(2);
    backButton->setPosition(Vec2(origin.x + winSize.width, origin.y));
    backButton->addClickEventListener([=](Ref* sender){
    	MyPurchase::purgePurchase();
        Director::getInstance()->replaceScene(HelloWorld::scene());
    });
    addChild(backButton);

    auto panel = Layout::create();
    panel->setAnchorPoint(Vec2(0.5,0.5));
    panel->setPosition(Vec2(origin.x + winSize.width/2, origin.y + winSize.height - 50));
    panel->setLayoutType(LayoutType::VERTICAL);
    addChild(panel);

    LinearLayoutParameter* llp = LinearLayoutParameter::create();
    llp->setGravity(LinearGravity::CENTER_HORIZONTAL);
    llp->setMargin(Margin(0, 0, 0, 50));

    auto purchaseButton = Button::create("btn_normal.png", "btn_pressed.png");
    purchaseButton->setTitleText("test purchase");
    purchaseButton->setScale(2);
    purchaseButton->setLayoutParameter(llp);
    purchaseButton->addClickEventListener([](Ref* pSender) {
        MyPurchase::MyPayMode mode = MyPurchase::MyPayMode::eGoogle;
        std::map<std::string, std::string> productInfo;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    	productInfo["IAPId"] = "android.test.purchased";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
        productInfo["product"] = "feature1";
#endif
        MyPurchase::getInstance()->payByMode(productInfo, MyPurchase::MyPayMode::eGoogle);
    });
    panel->addChild(purchaseButton);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    auto unfulfilledConsumablesButton = Button::create("btn_normal.png", "btn_pressed.png");
    unfulfilledConsumablesButton->setTitleText("report consumable fulfillment");
    unfulfilledConsumablesButton->setScale(2);
    unfulfilledConsumablesButton->setLayoutParameter(llp);
    unfulfilledConsumablesButton->addClickEventListener([](Ref* pSender) {
        plugin::PluginParam productIdParam();
        plugin::PluginParam transactionIdParam();
        MyPurchase::getInstance()->reportConsumablePurchase("consumable1", "{00000001-0000-0000-0000-000000000000}");
    });
    panel->addChild(unfulfilledConsumablesButton);

    auto allUnfulfilledButton = Button::create("btn_normal.png", "btn_pressed.png");
    allUnfulfilledButton->setTitleText("get unfulfilled consumables");
    allUnfulfilledButton->setScale(2);
    allUnfulfilledButton->setLayoutParameter(llp);
    allUnfulfilledButton->addClickEventListener([](Ref* pSender) {
        std::string result = MyPurchase::getInstance()->getPlugin()->callStringFuncWithParam("getUnfulfilledConsumables", NULL);
        MessageBox(result.c_str(), "Unfulfilled consumables result");
    });
    panel->addChild(allUnfulfilledButton);

    auto listingItemsButton = Button::create("btn_normal.png", "btn_pressed.png");
    listingItemsButton->setTitleText("get product IDs");
    listingItemsButton->setScale(2);
    listingItemsButton->setLayoutParameter(llp);
    listingItemsButton->addClickEventListener([](Ref* pSender) {
        std::string result = MyPurchase::getInstance()->getPlugin()->callStringFuncWithParam("getAllListingItems", NULL);
        MessageBox(result.c_str(), "Product IDs");
    });
    panel->addChild(listingItemsButton);



#endif
    /*
    //Google IAP button
    auto btnGoogle = Button::create("btn_normal.png","btn_pressed.png");
    btnGoogle->setTitleText("Google");
    btnGoogle->setScale(2);
    btnGoogle->addClickEventListener([=](Ref* sender){
    	//Perform IAP callback
        TProductInfo pInfo;
        MyPurchase::MyPayMode mode = MyPurchase::MyPayMode::eGoogle;
    	pInfo["IAPId"] = "android.test.purchased";
        MyPurchase::getInstance()->payByMode(pInfo, mode);

    });
    panel->addChild(btnGoogle);    
    */

    //MenuItemFont* testPluginPurchase = MenuItemFont::create("Test purchase", CC_CALLBACK_1([](Ref* pSender) {}, this));
    //MenuItemFont* getUnfulfilledConsumables = MenuItemFont::create("Query unfulfilled consumables", CC_CALLBACK_1(TestIAP::queryUnfulfilledConsumables, this));
    //MenuItemFont* reportFulfillment = MenuItemFont::create("Report fulfillment", CC_CALLBACK_1(TestIAP::reportFulfillment, this));
    //MenuItemFont* listingItems = MenuItemFont::create("Get all product IDs", CC_CALLBACK_1(TestIAP::getAllListingItems, this));

    //auto testMenu = Menu::create(testPluginPurchase, /*getUnfulfilledConsumables, reportFulfillment, listingItems, */NULL);
    //testMenu->alignItemsVertically();
    //testMenu->setPosition(Vec2(winSize.width / 2, winSize.height - (testMenu->getContentSize().height / 2)));
    //this->addChild(testMenu, 1);

    //label = LabelTTF::create("new session", "Arial", 20);
    //label->setPosition(Vec2(winSize.width / 2, label->getContentSize().height));
    //this->addChild(label, 1);



    return true;
}
