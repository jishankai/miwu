//
//  WS9Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__WS9Loader__
#define __miwu__WS9Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "WS9.h"

class WS9Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WS9Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WS9);
    
};


#endif /* defined(__miwu__WS9Loader__) */
