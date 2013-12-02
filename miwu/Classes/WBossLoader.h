//
//  WBossLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__WBossLoader__
#define __miwu__WBossLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "WBoss.h"

class WBossLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WBossLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WBoss);
    
};


#endif /* defined(__miwu__WBossLoader__) */
