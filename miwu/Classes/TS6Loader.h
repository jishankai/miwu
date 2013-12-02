//
//  TS6Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__TS6Loader__
#define __miwu__TS6Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "TS6.h"

class TS6Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TS6Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(TS6);
    
};


#endif /* defined(__miwu__TS6Loader__) */
