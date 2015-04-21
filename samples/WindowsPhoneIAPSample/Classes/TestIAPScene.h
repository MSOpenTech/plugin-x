#ifndef __TESTIAP_SCENE_H__
#define __TESTIAP_SCENE_H__

#include "cocos2d.h"
#include "ProtocolIAP.h"

class TestIAP : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TestIAP);

    void loadPlugin(cocos2d::Ref* pSender);
	void runTestPurchase(cocos2d::Ref* pSender);
	void unloadPlugin(cocos2d::Ref* pSender);
	void queryUnfulfilledConsumables(cocos2d::Ref* pSender);
	void reportFulfillment(cocos2d::Ref* pSender);
	void getAllListingItems(cocos2d::Ref* pSender);

	cocos2d::plugin::ProtocolIAP* iap;
    void purchaseCallback(int ret, std::string msg);
    cocos2d::LabelTTF* label;
};

#endif // __HELLOWORLD_SCENE_H__
