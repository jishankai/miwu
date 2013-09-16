//
//  InviteInviteer.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "InviteInviteer.h"

#include "LevelInviteer.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCNode* InviteInviteer::load()
{
    cocos2d::extension::CCNodeInviteerLibrary * ccNodeInviteerLibrary = cocos2d::extension::CCNodeInviteerLibrary::newDefaultCCNodeInviteerLibrary();
    
    ccNodeInviteerLibrary->registerCCNodeInviteer("Invite", InviteInviteer::loader());
    
    
    /* Create an autorelease CCBReader. */
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeInviteerLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    cocos2d::CCNode * node = ccbReader->readNodeGraphFromFile("Invite.ccbi");
    
    return node;
}