//
//  InviteLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__InviteLoader__
#define __miwu__InviteLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Invite.h"

class InviteLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(InviteLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Invite);
    
};


#endif /* defined(__miwu__InviteLoader__) */
