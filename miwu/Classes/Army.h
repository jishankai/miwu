//
//  Army.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__Army__
#define __miwu__Army__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "LayerWithDialog.h"

class Army : public LayerWithDialog
{
private:
    cocos2d::CCSprite* s1;
    cocos2d::CCSprite* s2;
    cocos2d::CCSprite* s3;
    cocos2d::CCSprite* s4;
    cocos2d::CCSprite* s5;
    cocos2d::CCSprite* s6;
    cocos2d::CCSprite* s7;
    cocos2d::CCSprite* s8;
    cocos2d::CCSprite* s9;
    cocos2d::CCSprite* show_s1;
    cocos2d::CCSprite* show_s2;
    cocos2d::CCSprite* show_s3;
    cocos2d::CCSprite* show_s4;
    cocos2d::CCSprite* show_s5;
    cocos2d::CCSprite* show_s6;
    cocos2d::CCSprite* show_s7;
    cocos2d::CCSprite* show_s8;
    cocos2d::CCSprite* show_s9;
    
    void clearArmyShow();
    
public:
    virtual void onEnter();
    
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Army, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__miwu__Army__) */
