//
//  BearLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__BearLoader__
#define __Miwu__BearLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Bear.h"

class BearLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BearLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Bear);
    
};


#endif /* defined(__Miwu__BearLoader__) */
