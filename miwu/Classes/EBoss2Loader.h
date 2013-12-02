//
//  EBoss2Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__EBoss2Loader__
#define __miwu__EBoss2Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "EBoss2.h"

class EBoss2Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(EBoss2Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(EBoss2);
    
};


#endif /* defined(__miwu__EBoss2Loader__) */
