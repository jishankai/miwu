//
//  TBossLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__TBossLoader__
#define __miwu__TBossLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "TBoss.h"

class TBossLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TBossLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(TBoss);
    
};


#endif /* defined(__miwu__TBossLoader__) */
