#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ProtocolAnalytics.h"

class TestAnalytics : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TestAnalytics);

    void loadPlugin(cocos2d::Ref* pSender);
    void unloadPlugin(cocos2d::Ref* pSender);
    void startSession(cocos2d::Ref* pSender);
    void stopSession(cocos2d::Ref* pSender);
    void logEvent(cocos2d::Ref* pSender);
    void logError(cocos2d::Ref* pSender);
    void startTimedEvent(cocos2d::Ref* pSender);
    void endTimedEvent(cocos2d::Ref* pSender);

    cocos2d::plugin::ProtocolAnalytics* analytics;
    cocos2d::LabelTTF* label;

};

#endif // __HELLOWORLD_SCENE_H__
