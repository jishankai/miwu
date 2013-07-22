//
//  Background.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __Miwu__Background__
#define __Miwu__Background__

#include "cocos2d.h"
#include "cocos-ext.h"

class Background : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    cocos2d::CCNode* level;
    
public:
    cocos2d::CCLayer* levelLayer;
    
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Background, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
};

#endif /* defined(__Miwu__Background__) */
