//
//  StatusInviteer.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__StatusInviteer__
#define __miwu__StatusInviteer__

#include "Status.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class StatusInviteer : public cocos2d::extension::CCLayerInviteer
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(StatusInviteer, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Status);
    
};

#endif /* defined(__miwu__StatusInviteer__) */
