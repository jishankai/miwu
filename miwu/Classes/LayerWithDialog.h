//
//  LayerWithDialog.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__LayerWithDialog__
#define __miwu__LayerWithDialog__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ApiParser.h"

class LayerWithDialog : public ApiParser, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    
public:
    cocos2d::CCSprite* dialog;
    virtual void onEnter();
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    virtual void registerWithTouchDispatcher();
    /*
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
     */
};

#endif /* defined(__miwu__LayerWithDialog__) */
