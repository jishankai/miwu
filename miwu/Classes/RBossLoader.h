//
//  RBossLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__RBossLoader__
#define __miwu__RBossLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "RBoss.h"

class RBossLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RBossLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RBoss);
    
};


#endif /* defined(__miwu__RBossLoader__) */
