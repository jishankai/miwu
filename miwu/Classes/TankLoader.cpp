//
//  TortoiseLoader.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "TortoiseLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* TortoiseLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("Tortoise", TortoiseLoader::loader());    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("Tortoise.ccbi");

    return node;
}
