//
//  MouseBackground.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__MouseBackground__
#define __miwu__MouseBackground__

#include "cocos2d.h"
#include "cocos-ext.h"

class MouseBackground : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    cocos2d::CCNode* level;
    CC_SYNTHESIZE(float, xSpeed, XSpeed);
    
public:
    cocos2d::CCLayer* levelLayer;
    
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MouseBackground, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
};

#endif /* defined(__miwu__MouseBackground__) */
