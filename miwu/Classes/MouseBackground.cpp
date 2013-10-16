//
//  MouseBackground.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "MouseBackground.h"

#include "cocos2d.h"
#include "MouseBackgroundLoader.h"
#include "MouseLevelLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void MouseBackground::onEnter()
{
    CCLayer::onEnter();
    
    level = MouseLevelLoader::load();
    levelLayer->addChild(level, 0, 201);
    
    this->setTouchEnabled(true);
    
    this->setXSpeed(0);
}

bool MouseBackground::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool MouseBackground::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer", CCLayer*, this->levelLayer);
    
    return false;
}
