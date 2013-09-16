//
//  InviteInviteer.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__InviteInviteer__
#define __miwu__InviteInviteer__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Invite.h"

class InviteInviteer : public cocos2d::extension::CCLayerInviteer
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(InviteInviteer, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Invite);
    
};


#endif /* defined(__miwu__InviteInviteer__) */
