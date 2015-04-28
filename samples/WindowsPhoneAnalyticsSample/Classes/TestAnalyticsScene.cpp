#include "TestAnalyticsScene.h"
#include "PluginManager.h"

#define TIMED_EVENT_ID "timed_event"
#define EVENT_ID "event_ping"
#define ERROR_ID "error_ping"
#define AZURE_KEY ""

USING_NS_CC;

Scene* TestAnalytics::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TestAnalytics::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TestAnalytics::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    MenuItemFont* loadAnalyticsPlugin = MenuItemFont::create("Load plugin", CC_CALLBACK_1(TestAnalytics::loadPlugin, this));
    MenuItemFont* killPlugin = MenuItemFont::create("Unload plugin", CC_CALLBACK_1(TestAnalytics::startSession, this));
    MenuItemFont* startAnalyticsSession = MenuItemFont::create("Start session", CC_CALLBACK_1(TestAnalytics::startSession, this));
    MenuItemFont* sendEvent = MenuItemFont::create("Log event", CC_CALLBACK_1(TestAnalytics::logEvent, this));
    MenuItemFont* sendError = MenuItemFont::create("Log error", CC_CALLBACK_1(TestAnalytics::logError, this));
    MenuItemFont* timedEventStart = MenuItemFont::create("Start timed event", CC_CALLBACK_1(TestAnalytics::startTimedEvent, this));
    MenuItemFont* timedEventEnd = MenuItemFont::create("Stop timed event", CC_CALLBACK_1(TestAnalytics::endTimedEvent, this));
    MenuItemFont* stopAnalyticsSession = MenuItemFont::create("Stop session", CC_CALLBACK_1(TestAnalytics::stopSession, this));

    
    auto testMenu = Menu::create(loadAnalyticsPlugin, killPlugin, startAnalyticsSession, 
        stopAnalyticsSession, sendEvent, sendError, timedEventStart, timedEventEnd, NULL);
    testMenu->alignItemsVertically();
    testMenu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - (testMenu->getContentSize().height / 2)));
    this->addChild(testMenu, 1);

    label = LabelTTF::create("new session", "Arial", 20);
    label->setPosition(Vec2(visibleSize.width / 2, label->getContentSize().height));
    this->addChild(label, 1);
    
    this->analytics = nullptr;
    return true;
}

void TestAnalytics::loadPlugin(Ref* pSender) {
    this->analytics = dynamic_cast<plugin::ProtocolAnalytics*>(plugin::PluginManager::getInstance()->loadPlugin("microsoftapplicationinsights"));
    if (this->analytics == nullptr) {
        MessageBox("Failed to load plugin", "Error");
        return;
    }
    label->setString("Plugin Loaded");
}

void TestAnalytics::unloadPlugin(Ref* pSender) {
    plugin::PluginManager::getInstance()->unloadPlugin("microsoftapplicationinsights");
    this->analytics = nullptr;
    label->setString("Plugin Unloaded");
}

void TestAnalytics::startSession(Ref* pSender) {
    analytics->startSession(AZURE_KEY);
    label->setString("Session started");
}

void TestAnalytics::stopSession(Ref* pSender) {
    analytics->stopSession();
    label->setString("Session started");
}

void TestAnalytics::logEvent(Ref* pSender) {
    analytics->logEvent(EVENT_ID);
    label->setString("Event logged");
}

void TestAnalytics::logError(Ref* pSender) {
    analytics->logError(ERROR_ID, "sample error");
    label->setString("Error logged");
}

void TestAnalytics::startTimedEvent(Ref* pSender) {
    analytics->logTimedEventBegin(TIMED_EVENT_ID);
    label->setString("Time event started");
}

void TestAnalytics::endTimedEvent(Ref* pSender) {
    analytics->logTimedEventEnd(TIMED_EVENT_ID);
    label->setString("Time event ended");
}






void TestAnalytics::menuCloseCallback(Ref* pSender)
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
