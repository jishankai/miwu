//
//  Status.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__Status__
#define __miwu__Status__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Miao.h"
#include "RBoss.h"

class Status : public cocos2d::CCLayer
{
private:
    bool init();
public:
    cocos2d::CCProgressTimer* bossBloodBar;
    cocos2d::CCProgressTimer* miaoBloodBar;

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Status, create);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);

    void pressedPelican(cocos2d::CCObject * pSender);
    void pressedBlood(cocos2d::CCObject * pSender);
    void pressedStone(cocos2d::CCObject * pSender);
};

#endif /* defined(__miwu__Status__) */
