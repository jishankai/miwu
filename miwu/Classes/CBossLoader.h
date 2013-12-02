//
//  CBossLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__CBossLoader__
#define __miwu__CBossLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "CBoss.h"

class CBossLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CBossLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CBoss);
    
};


#endif /* defined(__miwu__CBossLoader__) */
