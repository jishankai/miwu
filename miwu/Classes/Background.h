//
//  Background.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__Background__
#define __miwu__Background__

#include "cocos2d.h"
#include "cocos-ext.h"

class Background : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    cocos2d::CCNode* level;
    CC_SYNTHESIZE(float, xSpeed, XSpeed);
    
public:
    cocos2d::CCLayer* levelLayer;
    
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Background, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    virtual void update(float delta);
};

#endif /* defined(__miwu__Background__) */
