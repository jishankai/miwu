//
//  S8Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__S8Loader__
#define __miwu__S8Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "S8.h"

class S8Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(S8Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(S8);
    
};


#endif /* defined(__miwu__S8Loader__) */
