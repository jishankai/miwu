//
//  Menu.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "Menu.h"

#include "MenuLoader.h"
#include "GameSceneLoader.h"

#include "Background.h"

#include "S8Loader.h"
#include "S2Loader.h"
#include "S1Loader.h"
#include "S6Loader.h"
#include "S3Loader.h"
#include "S5Loader.h"
#include "S9Loader.h"
#include "S7Loader.h"
#include "S4Loader.h"
#include "MiaoLoader.h"
#include "PauseLoader.h"

#include "StaticData.h"
#include "JsonBox.h"
#include "Load.h"
#include "Process.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define kCJMiaoSpeed 30

bool Menu::init()
{
        
    return true;
}

void Menu::onEnter()
{
    CCLayer::onEnter();
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
    
    GameScene* gameScene = GameScene::sharedScene();
    backgroundLayer = gameScene->backgroundLayer;
    
    levelLayer = ((Background*)backgroundLayer->getChildByTag(101))->levelLayer;
    level = dynamic_cast<Level*>(levelLayer->getChildByTag(201));
    
    food = 0;
    mana = 0;
    
    CCSprite* redBar = CCSprite::createWithSpriteFrameName("progress_bar_mana.png");
    redProcessBar = CCProgressTimer::create(redBar);
    redProcessBar->setType(kCCProgressTimerTypeBar);
    redProcessBar->setMidpoint(CCPointZero);
    redProcessBar->setBarChangeRate(ccp(1.0f,0));
    redProcessBar->setAnchorPoint(CCPointZero);
    redProcessBar->setPosition(CCPointZero);
    redProcessBar->setPercentage(0);
    this->getChildByTag(1)->addChild(redProcessBar);
    
    CCSprite* blueBar = CCSprite::createWithSpriteFrameName("progress_bar_mana.png");
    blueProcessBar = CCProgressTimer::create(blueBar);
    blueProcessBar->setType(kCCProgressTimerTypeBar);
    blueProcessBar->setMidpoint(ccp(1,1));
    blueProcessBar->setBarChangeRate(ccp(1.0f,0));
    blueProcessBar->setAnchorPoint(ccp(0.1f,0));
    blueProcessBar->setPosition(CCPointZero);
    blueProcessBar->setPercentage(0);
    this->getChildByTag(2)->addChild(blueProcessBar);
    
    // Schedule a selector that is called every frame
    this->scheduleUpdate();
}

SEL_MenuHandler Menu::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedPause:", Menu::pressedPause);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS1:", Menu::pressedS1);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS2:", Menu::pressedS2);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS3:", Menu::pressedS3);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS4:", Menu::pressedS4);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS5:", Menu::pressedS5);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS6:", Menu::pressedS6);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS7:", Menu::pressedS7);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS8:", Menu::pressedS8);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedS9:", Menu::pressedS9);
    
    return NULL;
}

SEL_CCControlHandler Menu::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    return NULL;
}

bool Menu::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool Menu::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "foodValue", CCLabelTTF*, this->foodValue);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "manaValue", CCLabelTTF*, this->manaValue);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "leftArrow", CCSprite*, this->leftArrow);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "rightArrow", CCSprite*, this->rightArrow);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pauseSprite", CCSprite*, this->pauseSprite);
    
    return false;
}

void Menu::pressedPause(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
        CCNode* pause = PauseLoader::load();
        pause->setAnchorPoint(CCPointZero);
        pause->setPosition(CCPointZero);
        this->addChild(pause);
        
        CCDirector::sharedDirector()->pause();
        CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    } else {
        CCDirector::sharedDirector()->resume();
        CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }
}

void Menu::winHandler()
{
    CCNode* pauseNode = PauseLoader::load();
    Pause* pause = dynamic_cast<Pause*>(pauseNode);
    pause->setAnchorPoint(CCPointZero);
    pause->setPosition(CCPointZero);
    pause->win->setVisible(true);
    this->addChild(pause);
    CCDirector::sharedDirector()->pause();
    CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    
    int star=1;
    int rewardGold=0;
    int rewardEquipId;
    char url[255];
    std::string server = STATIC_DATA_STRING("server");
    int level = Process::mapType*Proces5s::levelNum;
    switch (Level) {
    case 1:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=20) {
        star++;
        rewardGold=rewardGold+25+10*((level-1)/6);
      }
      if(level->s1_call>=5){
        star++;
        rewardEquipId=;
      }
      break;
    case 2:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=20) {
        star++;
        rewardGold=rewardGold+25+10*((level-1)/6);
      }
      //todo
      break;
    case 3:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=20) {
        star++;
        rewardGold=rewardGold+25+10*((level-1)/6);
      }
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 4:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=20) {
        star++;
        rewardGold=rewardGold+25+10*((level-1)/6);
      }
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 5:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=20) {
        rewardGold=rewardGold+25+10*((level-1)/6);
        star++;
      }
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 6:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=20) {
        rewardGold=rewardGold+25+10*((level-1)/6);
        star++;
      }
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 7:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 8:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s2_call>=5)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 9:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 10:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 11:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 12:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s1_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=50)
        star++;
      break;
    case 13:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 14:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 15:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 16:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 17:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 18:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 19:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s1_call==0)
        star++;
      break;
    case 20:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s1_call==0)
        star++;
      break;
    case 21:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 22:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 23:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=60)
        star++;
      break;
    case 24:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s2_call==0)
        star++;
      break;
    case 25:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s2_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=70)
        star++;
      break;
    case 26:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=70)
        star++;
      break;
    case 27:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=70)
        star++;
      break;
    case 28:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=70)
        star++;
      break;
    case 29:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=70)
        star++;
      break;
    case 30:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=70)
        star++;
      break;
    case 31:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->soldier_dead<=15)
        star++;
      break;
    case 32:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s3_call>=5)
        star++;
      if(level->soldier_dead<=15)
        star++;
      break;
    case 33:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s3_call>=5)
        star++;
      if(level->soldier_dead<=15)
        star++;
      break;
    case 34:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s3_call>=5)
        star++;
      if(level->soldier_dead<=15)
        star++;
      break;
    case 35:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->soldier_dead<=15)
        star++;
      break;
    case 36:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s3_call==0)
        star++;
      if(level->soldier_dead<=15)
        star++;
      break;
    case 37:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=80)
        star++;
      break;
    case 38:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s1_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=80)
        star++;
      break;
    case 39:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s2_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=80)
        star++;
      break;
    case 40:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=80)
        star++;
      break;
    case 41:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=80)
        star++;
      break;
    case 42:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=80)
        star++;
      break;
    case 43:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s4_call>=5)
        star++;
      break;
    case 44:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s4_call>=5)
        star++;
      break;
    case 45:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s4_call>=5)
        star++;
      break;
    case 46:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 47:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 48:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 49:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 50:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 51:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 52:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 53:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 54:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 55:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s5_call>=5)
        star++;
      break;
    case 56:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s5_call>=5)
        star++;
      break;
    case 57:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s5_call>=5)
        star++;
      break;
    case 58:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 59:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 60:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s1_call==0&&level->s2_call==0)
        star++;
      break;
    case 61:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 62:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 63:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s2_call==0&&level->s3_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 64:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s2_call==0&&level->s3_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 65:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 66:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 67:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s6_call>=5)
        star++;
      break;
    case 68:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s6_call>=5)
        star++;
      break;
    case 69:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s6_call>=5)
        star++;
      break;
    case 70:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s2_call==0&&level->s8_call==0)
        star++;
      break;
    case 71:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 72:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 73:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 74:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s1_call==0)
        star++;
      break;
    case 75:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 76:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 77:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 78:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s7_call>=5)
        star++;
      break;
    case 79:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s7_call>=5)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 80:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s7_call>=5)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 81:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s6_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 82:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s4_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 83:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s5_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 84:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s3_call==0&&level->s4_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 85:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->soldier_dead<=15)
        star++;
      break;
    case 86:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s1_call==0)
        star++;
      if(level->soldier_dead<=15)
        star++;
      break;
    case 87:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->soldier_dead<=15)
        star++;
      break;
    case 88:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->soldier_dead<=15)
        star++;
      break;
    case 89:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s4_call==0)
        star++;
      if(level->soldier_dead<=15)
        star++;
      break;
    case 90:
      rewardGold=rewardGold+15+10*((level-1)/6);
      //todo
      if(level->soldier_dead<=15)
        star++;
      break;
    case 91:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      if(level->s2_call==0&&level->s8_call==0)
        star++;
      break;
    case 92:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      if(level->s7_call==0)
        star++;
      break;
    case 93:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      //todo
      break;
    case 94:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      //todo
      break;
    case 95:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      //todo
      break;
    case 96:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      if(level->s5_call==0&&level->s6_call==0)
        star++;
      break;
    case 97:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      if(level->s8_call>=5)
        star++;
      break;
    case 98:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      if(level->s8_call>=5)
        star++;
      break;
    case 99:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      if(level->s8_call>=5)
        star++;
      break;
    case 100:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      //todo
      break;
    case 101:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->s1_call==0)
        star++;
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      break;
    case 102:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->hp*100/level->miao->maxHp>=85)
        star++;
      //todo
      break;
    case 103:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 104:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s4_call==0)
        star++;
      break;
    case 105:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      if(level->s8_call==0)
        star++;
      break;
    case 106:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 107:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 108:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=15)
        star++;
      //todo
      break;
    case 109:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->isMaxHp())
        star++;
      //todo
      break;
    case 110:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->isMaxHp())
        star++;
      if(level->s9_call>=5)
        star++;
      break;
    case 111:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->isMaxHp())
        star++;
      //todo
      break;
    case 112:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->isMaxHp())
        star++;
      if(level->s8_call==0)
        star++;
      break;
    case 113:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->isMaxHp())
        star++;
      if(level->s8_call==0)
        star++;
      break;
    case 114:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->miao->isMaxHp())
        star++;
      //todo
      break;
    case 115:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=10)
        star++;
      if(level->s2_call==0&&level->s8_call==0)
        star++;
      break;
    case 116:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=10)
        star++;
      if(level->s8_call>=5)
        star++;
      break;
    case 117:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=10)
        star++;
      //todo
      break;
    case 118:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=10)
        star++;
      if(level->s1_call==0)
        star++;
      break;
    case 119:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=10)
        star++;
      if(level->s8_call==&&level->s9_call==0)
        star++;
      break;
    case 120:
      rewardGold=rewardGold+15+10*((level-1)/6);
      if(level->soldier_dead<=10)
        star++;
      //todo
      break;
    }
    sprintf(url, "%sbattle/winApi&level=%d&stars=%d&SID=%s", server.c_str(), level, 3, Load::sharedSessionId.c_str());
    cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
    request->setUrl(url);
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(Menu::onBattleWinRequestCompleted));
    request->setTag("battle win");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
}

void Menu::spriteMoveFinished(CCNode* sender)
{
	CCSprite *sprite = (CCSprite *)sender;
	this->removeChild(sprite, true);
}

void Menu::pressedS1(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
    food-=10;
    
    CCNode* s1 = S1Loader::load();
    
    // Determine where to spawn the target along the Y axis
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	float minY = s1->getContentSize().height/2+120;
	float maxY = winSize.height - 180 -  s1->getContentSize().height/2;
	int rangeY = (int)(maxY - minY);
	// srand( TimGetTicks() );
	int actualY = ( rand() % rangeY ) + (int)minY;
    
    s1->setPosition(ccp(s1->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
    s1->setTag(101);
    level->addChild(s1, 640-actualY);
    level->soldiers->addObject(s1);
    level->s1_call++;
    }
}

void Menu::pressedS2(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
      food-=27;
 
      CCNode* s2 = S2Loader::load();
    
      // Determine where to spawn the target along the Y axis
      CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
      float minY = s2->getContentSize().height/2+120;
      float maxY = winSize.height - 180 -  s2->getContentSize().height/2;
      int rangeY = (int)(maxY - minY);
      // srand( TimGetTicks() );
      int actualY = ( rand() % rangeY ) + (int)minY;
    
      s2->setPosition(ccp(s2->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
      s2->setTag(102);
      level->addChild(s2, 640-actualY);
      level->_soldiers->addObject(s2);
      level->s2_call++;
    }
}

void Menu::pressedS3(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
    food-=28;
    
    CCNode* s3 = S3Loader::load();
    
    // Determine where to spawn the target along the Y axis
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	float minY = s3->getContentSize().height/2+120;
	float maxY = winSize.height - 180 -  s3->getContentSize().height/2;
	int rangeY = (int)(maxY - minY);
	// srand( TimGetTicks() );
	int actualY = ( rand() % rangeY ) + (int)minY;
    
    s3->setPosition(ccp(s3->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
    s3->setTag(103);
    level->addChild(s3, 640-actualY);
    level->_soldiers->addObject(s3);
    level->s3_call++;

    CCObject* et = NULL;
    float nearestDist = 960;
    float enemyX = 0;
    GameObject* pNearestEnemy = NULL;
    CCARRAY_FOREACH(level->_enimies, et)
    {
        GameObject* pEnemy = dynamic_cast<GameObject*>(et);
        if(nearestDist>pEnemy->getPositionX()) {
            enemyX = pEnemy->getPositionX() - 0.8*pEnemy->getXSpeed();
            if (enemyX < nearestDist)
            {
                pNearestEnemy = pEnemy;
                nearestDist = enemyX;
            }
        }
    }
    if (nearestDist == 960) {
        if (et != NULL) {
            pNearestEnemy = dynamic_cast<GameObject*>(et);
        }
    }
    if (pNearestEnemy!=NULL) {
        CCFiniteTimeAction* actionMove = CCMoveTo::create(0.8f, ccp(pNearestEnemy->getPositionX() - 0.8*pNearestEnemy->getXSpeed(), pNearestEnemy->getPositionY()));
        s3->runAction(actionMove);
    }
    }
}

void Menu::pressedS4(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
    food-=30;

    CCNode* s4 = S4Loader::load();
    
    // Determine where to spawn the target along the Y axis
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	float minY = s4->getContentSize().height/2+120;
	float maxY = winSize.height - 180 -  s4->getContentSize().height/2;
	int rangeY = (int)(maxY - minY);
	// srand( TimGetTicks() );
	int actualY = ( rand() % rangeY ) + (int)minY;
    
    s4->setPosition(ccp(s4->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
    s4->setTag(104);
    level->addChild(s4, 640-actualY);
    level->_soldiers->addObject(s4);
    level->s4_call++;
    }
}

void Menu::pressedS5(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
    food-=49;
    
    CCNode* s5 = S5Loader::load();
    
    // Determine where to spawn the target along the Y axis
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	float minY = s5->getContentSize().height/2+120;
	float maxY = winSize.height - 180 -  s5->getContentSize().height/2;
	int rangeY = (int)(maxY - minY);
	// srand( TimGetTicks() );
	int actualY = ( rand() % rangeY ) + (int)minY;
    
    s5->setPosition(ccp(s5->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
    s5->setTag(105);
    level->addChild(s5, 640-actualY);
    level->_soldiers->addObject(s5);
    level->s5_call++;
    }
}

void Menu::pressedS6(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
        food-=97;
        CCNode* s6 = S6Loader::load();
    
    // Determine where to spawn the target along the Y axis
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	float minY = s6->getContentSize().height/2+120;
	float maxY = winSize.height - 180 -  s6->getContentSize().height/2;
	int rangeY = (int)(maxY - minY);
	// srand( TimGetTicks() );
	int actualY = ( rand() % rangeY ) + (int)minY;
    
    s6->setPosition(ccp(s6->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
    s6->setTag(106);
    level->addChild(s6, 640-actualY);
    level->_soldiers->addObject(s6);
    level->s6_call++;
    }
}

void Menu::pressedS7(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
        food-=44.5;
        CCNode* s7 = S7Loader::load();
    
    // Determine where to spawn the target along the Y axis
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	float minY = s7->getContentSize().height/2+120;
	float maxY = winSize.height - 180 -  s7->getContentSize().height/2;
	int rangeY = (int)(maxY - minY);
	// srand( TimGetTicks() );
	int actualY = ( rand() % rangeY ) + (int)minY;
    
    s7->setPosition(ccp(s7->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
    s7->setTag(107);
    level->addChild(s7, 640-actualY);
    level->_soldiers->addObject(s7);
    level->s7_call++;
    }
}

void Menu::pressedS8(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
        food-=76.5;
        CCNode* s8 = S8Loader::load();
    
    // Determine where to spawn the target along the Y axis
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	float minY = s8->getContentSize().height/2+150;
	float maxY = winSize.height - 150 -  s8->getContentSize().height/2;
	int rangeY = (int)(maxY - minY);
	// srand( TimGetTicks() );
	int actualY = ( rand() % rangeY ) + (int)minY;
    
    s8->setPosition(ccp(s8->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
    s8->setTag(108);
    level->addChild(s8, 640-actualY);
    level->_soldiers->addObject(s8);
    level->s8_call++;
    }
}

void Menu::pressedS9(cocos2d::CCObject *pSender)
{
    if(!CCDirector::sharedDirector()->isPaused()) {
        food-=96;
        CCNode* s9 = S9Loader::load();
    
    // Determine where to spawn the target along the Y axis
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	float minY = s9->getContentSize().height/2+120;
	float maxY = winSize.height - 180 -  s9->getContentSize().height/2;
	int rangeY = (int)(maxY - minY);
	// srand( TimGetTicks() );
	int actualY = ( rand() % rangeY ) + (int)minY;
    
    s9->setPosition(ccp(s9->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
    s9->setTag(109);
    level->addChild(s9, 640-actualY);
    level->_soldiers->addObject(s9);
    level->s9_call++;
    }
}

void Menu::update(float delta)
{
    food += delta;
    mana += delta;
    
    CCString* newFood = CCString::createWithFormat("%d", int(food));
    foodValue->setString(newFood->getCString());
    redProcessBar->setPercentage(food);
    CCString* newMana = CCString::createWithFormat("%d", int(mana));
    manaValue->setString(newMana->getCString());
    blueProcessBar->setPercentage(mana);
}

void Menu::ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent)
{
    CCTouch* pTouch = (CCTouch*)(pTouches->anyObject());
    CCPoint location = pTouch->getLocation();
    CCRect* pLeftTextureRect = new CCRect(leftArrow->getPositionX(), leftArrow->getPositionY(), leftArrow->getContentSize().width, leftArrow->getContentSize().height);
    CCRect* pRightTextureRect = new CCRect(rightArrow->getPositionX(), rightArrow->getPositionY(), rightArrow->getContentSize().width, rightArrow->getContentSize().height);
    CCRect* pPauseTextureRect = new CCRect(pauseSprite->getPositionX(), pauseSprite->getPositionY(), pauseSprite->getContentSize().width, pauseSprite->getContentSize().height);
    GameObject* miao = dynamic_cast<GameObject*>(level->miao);
    Background* bgLayer = (Background*)backgroundLayer->getChildByTag(101);
    if (pPauseTextureRect->containsPoint(location)) {
        pressedPause(this);
    } else if (pLeftTextureRect->containsPoint(location) && miao->getPositionX()>0) {
        //if (bgLayer->getPositionX()<-100 and bgLayer->getPositionX()>-480) {
        if (bgLayer->getPositionX()+miao->getPositionX()<=0 or bgLayer->getPositionX()+miao->getPositionX()>320) {
            bgLayer->setPosition(ccp(100-miao->getPositionX()>-480?100-miao->getPositionX():-480, 0));
            //miao->setPosition(ccp(100,miao->getPositionY()));
        }
        miao->setXSpeed(-1*kCJMiaoSpeed);
        bgLayer->setXSpeed(kCJMiaoSpeed);
        //CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(miao->getUserObject());
        //animationManager->runAnimationsForSequenceNamed("walk");
    } else if (pRightTextureRect->containsPoint(location) && miao->getPositionX()<960) {
        if (bgLayer->getPositionX()+miao->getPositionX()<=0 or bgLayer->getPositionX()+miao->getPositionX()>320) {
            bgLayer->setPosition(ccp(100-miao->getPositionX()>-480?100-miao->getPositionX():-480, 0));
            //miao->setPosition(ccp(100,miao->getPositionY()));
        }
        miao->setXSpeed(kCJMiaoSpeed);
        bgLayer->setXSpeed(-1*kCJMiaoSpeed);
        //CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(miao->getUserObject());
        //animationManager->runAnimationsForSequenceNamed("walk");
    }
    
}

void Menu::ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent)
{
    CCTouch* pTouch = (CCTouch*)(pTouches->anyObject());
    CCPoint location = pTouch->getLocation();
    CCRect* pLeftTextureRect = new CCRect(leftArrow->getPositionX(), leftArrow->getPositionY(), leftArrow->getContentSize().width, leftArrow->getContentSize().height);
    CCRect* pRightTextureRect = new CCRect(rightArrow->getPositionX(), rightArrow->getPositionY(), rightArrow->getContentSize().width, rightArrow->getContentSize().height);
    GameObject* miao = dynamic_cast<GameObject*>(level->miao);
    Background* bgLayer = (Background*)backgroundLayer->getChildByTag(101);
    if (pLeftTextureRect->containsPoint(location) && miao->getPositionX()>0 && miao->getXSpeed()==0) {
        
        miao->setXSpeed(-1*kCJMiaoSpeed);
        bgLayer->setXSpeed(kCJMiaoSpeed);
        //CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(miao->getUserObject());
        //animationManager->runAnimationsForSequenceNamed("walk");
    } else if (pRightTextureRect->containsPoint(location) && miao->getPositionX()>0 && miao->getXSpeed()==0) {
        miao->setXSpeed(kCJMiaoSpeed);
        bgLayer->setXSpeed(-1*kCJMiaoSpeed);
        //CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(miao->getUserObject());
        //animationManager->runAnimationsForSequenceNamed("walk");
    } else if (miao->getXSpeed()!=0) {
        miao->setXSpeed(0);
        bgLayer->setXSpeed(0);
    }
}

void Menu::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
    GameObject* miao = dynamic_cast<GameObject*>(level->miao);
    Background* bgLayer = (Background*)backgroundLayer->getChildByTag(101);
    if (miao->getXSpeed()!=0) {
        miao->setXSpeed(0);
        bgLayer->setXSpeed(0);
    }
}

void Menu::onBattleWinRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response)
{
    if (!response)
    {
        return;
    }
    
    // You can get original request type from: response->request->reqType
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        CCLog("%s completed", response->getHttpRequest()->getTag());
    }
    
    int statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
    CCLog("response code: %d", statusCode);
    
    if (!response->isSucceed())
    {
        CCLog("response failed");
        CCLog("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    // dump data
    std::vector<char> *buffer = response->getResponseData();
    const std::string jsonStr(buffer->begin(),buffer->end());
    JsonBox::Value json;
    json.loadFromString(jsonStr);
    
    if (json["data"]["playerId"].getInt()) {
        Load::sharedPlayer.level = json["data"]["process"]["count"].getInt();
        Load::sharedPlayer.process = json["data"]["process"]["levels"].getArray();
    }
}

