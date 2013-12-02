//
//  WBoss2Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__WBoss2Loader__
#define __miwu__WBoss2Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "WBoss2.h"

class WBoss2Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WBoss2Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WBoss2);
    
};


#endif /* defined(__miwu__WBoss2Loader__) */
