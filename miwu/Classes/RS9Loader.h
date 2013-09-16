//
//  RS9Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__RS9Loader__
#define __miwu__RS9Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "RS9.h"

class RS9Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RS9Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RS9);
    
};


#endif /* defined(__miwu__RS9Loader__) */
