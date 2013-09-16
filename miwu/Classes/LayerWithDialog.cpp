//
//  LayerWithDialog.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "LayerWithDialog.h"

#include "cocos2d.h"

USING_NS_CC;
USING_NS_CC_EXT;

void LayerWithDialog::onEnter()
{
    CCLayer::onEnter();
    
    this->setTouchEnabled(true);
}

bool LayerWithDialog::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool LayerWithDialog::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dialog", CCSprite*, this->dialog);
    
    return false;
}
void LayerWithDialog::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -1, true);
}

/*
void LayerWithDialog::ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent)
{
    CCTouch* pTouch = (CCTouch*)(pTouches->anyObject());
    CCPoint location = pTouch->getLocation();
    
}

void LayerWithDialog::ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent)
{
}
*/