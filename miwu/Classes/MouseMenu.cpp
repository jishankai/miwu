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

#include "Background.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define kCJMiaoSpeed 30

bool MouseMenu::init()
{
        
    return true;
}

void MouseMenu::onEnter()
{
    CCLayer::onEnter();
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
    
    GameScene* gameScene = GameScene::sharedScene();
    backgroundLayer = gameScene->backgroundLayer;
    
    levelLayer = ((Background*)backgroundLayer->getChildByTag(101))->levelLayer;
    level = dynamic_cast<Level*>(levelLayer->getChildByTag(201));
    
    // Schedule a selector that is called every frame
    this->scheduleUpdate();
}

void MouseMenu::ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent)
{
   
    
}

void MouseMenu::ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent)
{
}

void MouseMenu::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
    
}

