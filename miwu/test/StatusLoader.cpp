//
//  StatusInviteer.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "StatusInviteer.h"
/*
#include "S1Inviteer.h"
#include "ZombieInviteer.h"
*/
USING_NS_CC;
USING_NS_CC_EXT;

CCNode* StatusInviteer::load()
{
    cocos2d::extension::CCNodeInviteerLibrary * ccNodeInviteerLibrary = cocos2d::extension::CCNodeInviteerLibrary::newDefaultCCNodeInviteerLibrary();
    
    ccNodeInviteerLibrary->registerCCNodeInviteer("Status", StatusInviteer::loader());/*
    ccNodeInviteerLibrary->registerCCNodeInviteer("S1", S1Inviteer::loader());
    ccNodeInviteerLibrary->registerCCNodeInviteer("Zombie", ZombieInviteer::loader());*/
    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeInviteerLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("Status.ccbi");

    return node;
}