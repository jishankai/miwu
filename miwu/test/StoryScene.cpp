//
//  StoryScene.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "StoryScene.h"

#include "MouseNormalGameScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCScene* StoryScene::scene()
{
    CCScene* scene = CCScene::create();
    
    StoryScene* layer = StoryScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool StoryScene::init()
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
    CCSprite* pNormalSprite = CCSprite::createWithSpriteFrameName("tx_miao.png");
    CCSprite* pSelectedSprite = CCSprite::createWithSpriteFrameName("tx_miao.png");
    CCMouseMenuItemSprite *pStartSprite = CCMouseMenuItemSprite::create(
                                                          pNormalSprite,
                                                          pSelectedSprite,
                                                          this,
                                                          menu_selector(StoryScene::pressedPlay));
    
	pStartSprite->setPosition(ccp(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/2));
    
    // create menu, it's an autorelease object
    CCMouseMenu* pMouseMenu = CCMouseMenu::create(pStartSprite, NULL);
    pMouseMenu->setPosition(CCPointZero);
    CCLayerColor* pColorLayer = CCLayerColor::create(ccc4(238, 118, 0, 255));
    this->addChild(pColorLayer);
    this->addChild(pMouseMenu, 1);
     
    return true;
}

void StoryScene::pressedPlay(cocos2d::CCObject *pSender)
{
    CCScene* pMouseNormalGameScene = MouseNormalGameScene::scene();
    CCDirector::sharedDirector()->replaceScene(pMouseNormalGameScene);
}