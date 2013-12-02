//
//  TS10Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__TS10Loader__
#define __miwu__TS10Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "TS10.h"

class TS10Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TS10Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(TS10);
    
};


#endif /* defined(__miwu__TS10Loader__) */
