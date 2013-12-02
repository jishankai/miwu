//
//  CBoss2Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__CBoss2Loader__
#define __miwu__CBoss2Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "CBoss2.h"

class CBoss2Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CBoss2Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CBoss2);
    
};


#endif /* defined(__miwu__CBoss2Loader__) */
