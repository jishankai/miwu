//
//  MouseMenu.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__MouseMenu__
#define __miwu__MouseMenu__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "MouseLevel.h"

class MouseMenu : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    cocos2d::CCLayer* levelLayer;
    cocos2d::CCLayer* backgroundLayer;
    MouseLevel* level;
    bool init();
    float randTime = 0;
    cocos2d::CCArray *_buttons;
    int buttonCount = 0;
    cocos2d::CCSprite* pauseSprite;
    cocos2d::CCSprite* miaoRound;
    
public:
    void update(float delta);
    virtual void onEnter();
    virtual void onExit();
    void pressedPause(cocos2d::CCObject * pSender);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MouseMenu, create);
    
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__miwu__MouseMenu__) */
