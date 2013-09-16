//
//  GameOverScene.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "GameOverScene.h"

#include "MainMenuScene.h"

#include "PauseLoader.h"
#include "Pause.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCScene* GameOverScene::scene()
{
    CCScene* scene = CCScene::create();
    
    GameOverScene* layer = GameOverScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    /*
    CCLabelTTF* pOverLabel = CCLabelTTF::create();
    CCString* pStr = CCString::createWithFormat("Game Over");
    pOverLabel->setString(pStr->getCString());
	pOverLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/2));
    CCLayerColor* pColorLayer = CCLayerColor::create(ccc4(0, 0, 0, 0));
    pColorLayer->addChild(pOverLabel);
    this->addChild(pColorLayer);
     */
    CCNode* pauseNode = PauseLoader::load();
    Pause* pause = dynamic_cast<Pause*>(pauseNode);
    pause->setAnchorPoint(CCPointZero);
    pause->setPosition(CCPointZero);
    pause->lose->setVisible(true);
    this->addChild(pause);
    
    return true;
}

void GameOverScene::pressedPlay(cocos2d::CCObject *pSender)
{
    CCScene* pGameScene = MainMenuScene::scene();
    CCDirector::sharedDirector()->replaceScene(pGameScene);
}