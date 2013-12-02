//
//  WS10Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__WS10Loader__
#define __miwu__WS10Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "WS10.h"

class WS10Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WS10Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WS10);
    
};


#endif /* defined(__miwu__WS10Loader__) */
