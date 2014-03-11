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
#include "Base.h"

class Status : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    
public:
    Miao* miao;
    Base* boss;
    float randTime = 0;
    cocos2d::CCArray *_soldiers;
	cocos2d::CCArray *_enimies;
    
    cocos2d::CCProgressTimer* bossBloodBar;
    cocos2d::CCProgressTimer* miaoBloodBar;

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Status, create);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual cocos2d::SEL_MouseMenuHandler onResolveCCBCCMouseMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);

    
    //virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCInvite *pInvite);
    //virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCInvite *pInvite);
    void pressedPelican(cocos2d::CCObject * pSender);
    void pressedBlood(cocos2d::CCObject * pSender);
    void pressedStone(cocos2d::CCObject * pSender);

    
    void update(float delta);
};

#endif /* defined(__miwu__Status__) */
