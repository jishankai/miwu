//
//  MouseMenu.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "MouseMenu.h"

#include "MouseMenuLoader.h"
#include "GameScene.h"

#include "S8Loader.h"
#include "S2Loader.h"
#include "S1Loader.h"
#include "S6Loader.h"
#include "S3Loader.h"
#include "S5Loader.h"
#include "S9Loader.h"
#include "S7Loader.h"
#include "S4Loader.h"
#include "PauseLoader.h"
#include "MouseBackground.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define kCJMiaoSpeed 30

bool MouseMenu::init()
{
        
    return true;
}

bool MouseMenu::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool MouseMenu::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pauseSprite", CCSprite*, this->pauseSprite);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "miaoRound", CCSprite*, this->miaoRound);
    
    return false;
}

void MouseMenu::onEnter()
{
    CCLayer::onEnter();
    
    _buttons = new CCArray;
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
    
    GameScene* gameScene = GameScene::sharedScene();
    backgroundLayer = gameScene->backgroundLayer;
    
    levelLayer = ((MouseBackground*)backgroundLayer->getChildByTag(101))->levelLayer;
    level = dynamic_cast<MouseLevel*>(levelLayer->getChildByTag(201));
    
    miaoRound->setZOrder(100);
    // Schedule a selector that is called every frame
    this->scheduleUpdate();
}

void MouseMenu::onExit()
{
    // Remove the scheduled selector
    this->unscheduleAllSelectors();
    
    _buttons->release();
    
    CCLayer::onExit();
}

void MouseMenu::pressedPause(cocos2d::CCObject *pSender)
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

void MouseMenu::update( float delta)
{
    randTime += delta;
    if (randTime >= 3 and buttonCount<8) {
        randTime = 0;
        CCSprite* squareBack = CCSprite::createWithSpriteFrameName("button_square_back_bigmouth.png");
        squareBack->setAnchorPoint(CCPointZero);
        squareBack->setPosition(CCPointZero);
        CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
        CCSprite* square = CCSprite::createWithSpriteFrameName("button_square_bigmouth.png");
        square->setAnchorPoint(CCPointZero);
        square->setPosition(ccp(winSize.width-square->getContentSize().width/2,16));
        square->addChild(squareBack);
    
        int soldierType = rand()%9;
        CCSprite* soldier;
        switch (soldierType) {
            case 1:
                soldier = CCSprite::createWithSpriteFrameName("s1_tx.png");
                break;
            case 2:
                soldier = CCSprite::createWithSpriteFrameName("s2_tx.png");
                break;
            case 3:
                soldier = CCSprite::createWithSpriteFrameName("s3_tx.png");
                break;
            case 4:
                soldier = CCSprite::createWithSpriteFrameName("s4_tx.png");
                break;
            case 5:
                soldier = CCSprite::createWithSpriteFrameName("s5_tx.png");
                break;
            case 6:
                soldier = CCSprite::createWithSpriteFrameName("s6_tx.png");
                break;
            case 7:
                soldier = CCSprite::createWithSpriteFrameName("s7_tx.png");
                break;
            case 8:
                soldier = CCSprite::createWithSpriteFrameName("s8_tx.png");
                break;
            case 0:
                soldier = CCSprite::createWithSpriteFrameName("s9_tx.png");
                soldierType = 9;
                break;
            default:
                break;
        }
        
        soldier->setAnchorPoint(CCPointZero);
        soldier->setPosition(ccp(5,6));
        square->addChild(soldier);
        square->setTag(soldierType);
       
        this->addChild(square);
        _buttons->addObject(square);
        
    }
    
    CCObject* st = NULL;
    buttonCount = 0;
    CCARRAY_FOREACH(_buttons, st)
    {
        CCSprite* buttonSprite = dynamic_cast<CCSprite*>(st);
        if (buttonSprite->getPositionX()>=15+buttonSprite->getContentSize().width*buttonCount) {
            buttonSprite->setPositionX(buttonSprite->getPositionX()-buttonSprite->getContentSize().width*0.5*delta);
        }
        buttonCount++;
    }
}

void MouseMenu::ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent)
{
    CCTouch* pTouch = (CCTouch*)(pTouches->anyObject());
    CCPoint location = pTouch->getLocation();
    
    CCRect* pPauseTextureRect = new CCRect(pauseSprite->getPositionX(), pauseSprite->getPositionY(), pauseSprite->getContentSize().width, pauseSprite->getContentSize().height);
    if (pPauseTextureRect->containsPoint(location)) {
        pressedPause(this);
    } else if(!CCDirector::sharedDirector()->isPaused()) {
        CCObject* st = NULL;
        CCARRAY_FOREACH(_buttons, st)
        {
            CCSprite* buttonSprite = dynamic_cast<CCSprite*>(st);
            CCRect* pTextureRect = new CCRect(buttonSprite->getPositionX(), buttonSprite->getPositionY(), buttonSprite->getContentSize().width, buttonSprite->getContentSize().height);
            if (pTextureRect->containsPoint(location)) {
                int soldierType = buttonSprite->getTag();
                CCNode* soldier;
                
                switch (soldierType) {
                    case 1:
                        soldier = S1Loader::load();
                        break;
                    case 2:
                        soldier = S2Loader::load();
                        break;
                    case 3:
                        soldier = S3Loader::load();
                        break;
                    case 4:
                        soldier = S4Loader::load();
                        break;
                    case 5:
                        soldier = S5Loader::load();
                        break;
                    case 6:
                        soldier = S6Loader::load();
                        break;
                    case 7:
                        soldier = S7Loader::load();
                        break;
                    case 8:
                        soldier = S8Loader::load();
                        break;
                    case 9:
                        soldier = S9Loader::load();
                        break;
                    default:
                        break;
                }
                
                // Determine where to spawn the target along the Y axis
                CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
                float minY = soldier->getContentSize().height/2+120;
                float maxY = winSize.height - 180 -  soldier->getContentSize().height/2;
                int rangeY = (int)(maxY - minY);
                // srand( TimGetTicks() );
                int actualY = ( rand() % rangeY ) + (int)minY;
                
                soldier->setPosition(ccp(soldier->getContentSize().width/2, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
                level->addChild(soldier, 640-actualY);
                level->_soldiers->addObject(soldier);
                
                this->removeChild(buttonSprite);
                _buttons->removeObject(buttonSprite);
            }
            
        }
    }
    
}

void MouseMenu::ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent)
{
}

void MouseMenu::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
    
}

