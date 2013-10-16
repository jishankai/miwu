//
//  MouseLevelLoader.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "MouseLevelLoader.h"
/*
#include "S1Loader.h"
#include "ZombieLoader.h"
*/
USING_NS_CC;
USING_NS_CC_EXT;

CCNode* MouseLevelLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("MouseLevel", MouseLevelLoader::loader());/*
    ccNodeLoaderLibrary->registerCCNodeLoader("S1", S1Loader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Zombie", ZombieLoader::loader());*/
    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("MouseLevel.ccbi");

    return node;
}