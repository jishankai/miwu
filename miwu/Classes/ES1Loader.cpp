//
//  ES1Loader.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "ES1Loader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* ES1Loader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("ES1", ES1Loader::loader());
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("ES1.ccbi");

    return node;
}
