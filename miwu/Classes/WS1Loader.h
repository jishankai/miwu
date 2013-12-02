//
//  WS1Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__WS1Loader__
#define __miwu__WS1Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "WS1.h"

class WS1Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WS1Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WS1);
    
};


#endif /* defined(__miwu__WS1Loader__) */
