//
//  WS8Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__WS8Loader__
#define __miwu__WS8Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "WS8.h"

class WS8Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WS8Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WS8);
    
};


#endif /* defined(__miwu__WS8Loader__) */
