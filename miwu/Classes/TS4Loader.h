//
//  TS4Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__TS4Loader__
#define __miwu__TS4Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "TS4.h"

class TS4Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TS4Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(TS4);
    
};


#endif /* defined(__miwu__TS4Loader__) */
