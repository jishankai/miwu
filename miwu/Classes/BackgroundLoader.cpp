//
//  BackgroundLoader.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "BackgroundLoader.h"

#include "LevelLoader.h"
#include "Process.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* BackgroundLoader::load()
{
    cocos2d::extension::CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    switch (Process::mapType) {
        case 1:
            ccNodeLoaderLibrary->registerCCNodeLoader("RBackground", BackgroundLoader::loader());
            break;
        case 2:
            ccNodeLoaderLibrary->registerCCNodeLoader("WBackground", BackgroundLoader::loader());
            break;
        case 3:
            ccNodeLoaderLibrary->registerCCNodeLoader("TBackground", BackgroundLoader::loader());
            break;
        case 4:
            ccNodeLoaderLibrary->registerCCNodeLoader("CBackground", BackgroundLoader::loader());
            break;
        case 5:
            ccNodeLoaderLibrary->registerCCNodeLoader("EBackground", BackgroundLoader::loader());
            break;
        default:
            ccNodeLoaderLibrary->registerCCNodeLoader("RBackground", BackgroundLoader::loader());
            break;
    }
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node;
    switch (Process::mapType) {
        case 1:
            node = ccbReader->readNodeGraphFromFile("RBackground.ccbi");
            break;
        case 2:
            node = ccbReader->readNodeGraphFromFile("WBackground.ccbi");
            break;
        case 3:
            node = ccbReader->readNodeGraphFromFile("TBackground.ccbi");
            break;
        case 4:
            node = ccbReader->readNodeGraphFromFile("CBackground.ccbi");
            break;
        case 5:
            node = ccbReader->readNodeGraphFromFile("EBackground.ccbi");
            break;
        default:
            node = ccbReader->readNodeGraphFromFile("RBackground.ccbi");
            break;
    }
    
    
    return node;
}