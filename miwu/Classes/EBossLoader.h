//
//  EBossLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__EBossLoader__
#define __miwu__EBossLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "EBoss.h"

class EBossLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(EBossLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(EBoss);
    
};


#endif /* defined(__miwu__EBossLoader__) */
