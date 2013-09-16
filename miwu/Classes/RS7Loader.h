//
//  RS7Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__RS7Loader__
#define __miwu__RS7Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "RS7.h"

class RS7Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RS7Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RS7);
    
};


#endif /* defined(__miwu__RS7Loader__) */
