//
//  TortoiseLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__TortoiseLoader__
#define __Miwu__TortoiseLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Tortoise.h"

class TortoiseLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TortoiseLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Tortoise);
    
};


#endif /* defined(__Miwu__TortoiseLoader__) */
