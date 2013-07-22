//
//  GameScene.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "GameScene.h"

#include "cocos2d.h"
#include "MainMenuSceneLoader.h"
#include "GameSceneLoader.h"
#include "BackgroundLoader.h"
#include "MenuLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

GameScene* GameScene::sharedInstance = NULL;

GameScene* GameScene::sharedScene()
{
    return sharedInstance;
}

CCScene* GameScene::scene()
{
    CCScene* scene = CCScene::create();
    sharedInstance = GameSceneLoader::load();
    
    scene->addChild(sharedInstance);
    
    return scene;
}

void GameScene::onEnter()
{
    CCLayer::onEnter();
    background = BackgroundLoader::load();
    menu = MenuLoader::load();
    
    backgroundLayer->addChild(background, 0, 101);
    menuLayer->addChild(menu, 1, 102);
}

bool GameScene::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool GameScene::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "backgroundLayer", CCLayer*, this->backgroundLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menuLayer", CCLayer*, this->menuLayer);
    return false;
}


void GameScene::handleGameOver()
{
    CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
}

void GameScene::handleLevelComplete()
{
    CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
}