//
//  RS2Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__RS2Loader__
#define __miwu__RS2Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "RS2.h"

class RS2Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RS2Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RS2);
    
};


#endif /* defined(__miwu__RS2Loader__) */
