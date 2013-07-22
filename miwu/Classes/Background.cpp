//
//  Background.cpp
//  Miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Background.h"

#include "cocos2d.h"
#include "BackgroundLoader.h"
#include "LevelLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Background::onEnter()
{
    CCLayer::onEnter();
    level = LevelLoader::load();
    levelLayer->addChild(level, 0, 201);
}

bool Background::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool Background::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer", CCLayer*, this->levelLayer);
    
    return false;
}
