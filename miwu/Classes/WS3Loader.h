//
//  WS3Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__WS3Loader__
#define __miwu__WS3Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "WS3.h"

class WS3Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WS3Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WS3);
    
};


#endif /* defined(__miwu__WS3Loader__) */
