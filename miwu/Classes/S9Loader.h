//
//  S9Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__S9Loader__
#define __miwu__S9Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "S9.h"

class S9Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(S9Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(S9);
    
};


#endif /* defined(__miwu__S9Loader__) */
