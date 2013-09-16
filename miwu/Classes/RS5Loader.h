//
//  RS5Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__RS5Loader__
#define __miwu__RS5Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "RS5.h"

class RS5Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RS5Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RS5);
    
};


#endif /* defined(__miwu__RS5Loader__) */
