//
//  Pause.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__Pause__
#define __miwu__Pause__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "LayerWithDialog.h"

class Pause : public LayerWithDialog
{
private:
    
public:
    cocos2d::CCSprite* win;
    cocos2d::CCSprite* lose;
    
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Pause, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__miwu__Pause__) */
