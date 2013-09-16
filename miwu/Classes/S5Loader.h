//
//  S5Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__S5Loader__
#define __miwu__S5Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "S5.h"

class S5Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(S5Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(S5);
    
};


#endif /* defined(__miwu__S5Loader__) */
