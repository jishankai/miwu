//
//  CBoss2Loader.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "CBoss2Loader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* CBoss2Loader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("CBoss2", CBoss2Loader::loader());    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("CBoss2.ccbi");

    return node;
}
