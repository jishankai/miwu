//
//  Status.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "Status.h"

#include "GameObject.h"
#include "MiaoLoader.h"
#include "RBossLoader.h"
#include "GameScene.h"
#include "Background.h"
#include "GameOverScene.h"
#include "MainMenuScene.h"

#include "Soldier.h"

#include "RS1Loader.h"
#include "RS2Loader.h"
#include "RS3Loader.h"
#include "RS4Loader.h"
#include "RS5Loader.h"
#include "RS6Loader.h"
#include "RS7Loader.h"
#include "RS8Loader.h"
#include "RS9Loader.h"
#include "RS10Loader.h"

#include "SimpleAudioEngine.h"

#define kCJScrollFilterFactor 0.1
#define kCJS1TargetOffset 156

USING_NS_CC;
USING_NS_CC_EXT;

bool Status::init()
{
    CCSprite* mBloodBar = CCSprite::createWithSpriteFrameName("blood_bar.png");
    miaoBloodBar = CCProgressTimer::create(mBloodBar);
    miaoBloodBar->setType(kCCProgressTimerTypeBar);
    miaoBloodBar->setMidpoint(CCPointZero);
    miaoBloodBar->setBarChangeRate(ccp(1.0f,0));
    miaoBloodBar->setPercentage(100);
    miaoBloodBar->setAnchorPoint(ccp(0,0.5f));
    miaoBloodBar->setPosition(ccp(43,24));
    
    CCSprite* bBloodBar = CCSprite::createWithSpriteFrameName("blood_bar.png");
    bossBloodBar = CCProgressTimer::create(bBloodBar);
    bossBloodBar->setType(kCCProgressTimerTypeBar);
    bossBloodBar->setMidpoint(ccp(1,1));
    bossBloodBar->setBarChangeRate(ccp(1.0f,0));
    bossBloodBar->setPercentage(100);
    bossBloodBar->setAnchorPoint(ccp(1,0.5f));
    bossBloodBar->setPosition(ccp(200,24));

    return true;
}

void Status::onEnter()
{
    CCLayer::onEnter();
    
    // Make sure touches are enabled
    //his->setTouchEnabled(true);
    this->getChildByTag(3)->addChild(miaoBloodBar);
    this->getChildByTag(4)->addChild(bossBloodBar);
}

void Status::onExit()
{
    // Remove the scheduled selector
    this->unscheduleAllSelectors();
    
    CCLayer::onExit();
}

SEL_MenuHandler Status::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedPelican:", Status::pressedPelican);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedBlood:", Status::pressedBlood);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedStone:", Status::pressedStone);
    
    return NULL;
}

SEL_CCControlHandler Status::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    return NULL;
}

void Status::pressedPelican(cocos2d::CCObject *pSender)
{
    CCLog("Use Pelicans");
}

void Status::pressedBlood(cocos2d::CCObject *pSender)
{
    CCLog("Use Blood");
}

void Status::pressedStone(cocos2d::CCObject *pSender)
{
    CCLog("Add Stone");
}
