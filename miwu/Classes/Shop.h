//
//  Shop.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__Shop__
#define __miwu__Shop__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "LayerWithDialog.h"

class Shop : public LayerWithDialog
{
private:
public:
    cocos2d::CCSprite* coin;
    cocos2d::CCSprite* treasure;
    cocos2d::CCSprite* ring;
    
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Shop, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__miwu__Shop__) */
