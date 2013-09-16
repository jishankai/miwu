//
//  AccountLoader.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "AccountLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* AccountLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("Account", AccountLoader::loader());
    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("Account.ccbi");
    
    return node;
}