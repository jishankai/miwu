//
//  TS1Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__TS1Loader__
#define __miwu__TS1Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "TS1.h"

class TS1Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TS1Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(TS1);
    
};


#endif /* defined(__miwu__TS1Loader__) */
