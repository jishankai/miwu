//
//  AccountLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__AccountLoader__
#define __miwu__AccountLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Account.h"

class AccountLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AccountLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Account);
    
};


#endif /* defined(__miwu__AccountLoader__) */
