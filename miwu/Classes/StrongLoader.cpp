//
//  DinosaurLoader.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "DinosaurLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* DinosaurLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("Dinosaur", DinosaurLoader::loader());
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("Dinosaur.ccbi");

    return node;
}
