//
//  TS1Loader.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "TS1Loader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* TS1Loader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("TS1", TS1Loader::loader());
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("TS1.ccbi");

    return node;
}
