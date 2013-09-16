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
    level->_soldiers->addObject(s1);
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
    
    CCObject* et = NULL;
    float nearestDist = 960;
    GameObject* pNearestEnemy = NULL;
    CCARRAY_FOREACH(level->_enimies, et)
    {
        GameObject* pEnemy = dynamic_cast<GameObject*>(et);
        if(nearestDist>pEnemy->getPositionX()) {
            nearestDist = pEnemy->getPositionX();
            pNearestEnemy = pEnemy;
        }
    }
    if (nearestDist==960) {
        if (et!=NULL) {
            pNearestEnemy = dynamic_cast<GameObject*>(et);
        }
    }
    if (pNearestEnemy!=NULL) {
        CCFiniteTimeAction* actionMove = CCMoveTo::create( 1.0f, ccp(960-pNearestEnemy->getPositionX(), pNearestEnemy->getPositionY()) );
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
    GameObject* miao = dynamic_cast<GameObject*>(level->miao);
    Background* bgLayer = (Background*)backgroundLayer->getChildByTag(101);
    if (pLeftTextureRect->containsPoint(location) && miao->getPositionX()>0) {
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

