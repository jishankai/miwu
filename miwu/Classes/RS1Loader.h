//
//  RS1Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__RS1Loader__
#define __miwu__RS1Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "RS1.h"

class RS1Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RS1Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RS1);
    
};


#endif /* defined(__miwu__RS1Loader__) */
