//
//  MouseGameScene.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "MouseGameScene.h"
#include "MouseMenuLoader.h"
#include "GameSceneLoader.h"
#include "BackgroundLoader.h"
#include "StatusLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCScene* MouseGameScene::scene()
{
    CCScene* scene = CCScene::create();
    sharedInstance = GameSceneLoader::load();

    sharedInstance->background = BackgroundLoader::load();
    sharedInstance->status = StatusLoader::load();
    sharedInstance->backgroundLayer->addChild(sharedInstance->background, 0, 101);
    sharedInstance->statusLayer->addChild(sharedInstance->status, 2, 102);
    sharedInstance->menu = MouseMenuLoader::load();
    sharedInstance->menuLayer->addChild(sharedInstance->menu, 1, 103);
    
    scene->addChild(sharedInstance);
    
    return scene;
}