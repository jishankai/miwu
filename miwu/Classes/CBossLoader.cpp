//
//  CBossLoader.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "CBossLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* CBossLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("CBoss", CBossLoader::loader());    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("CBoss.ccbi");

    return node;
}
