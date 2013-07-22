//
//  RatLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__RatLoader__
#define __Miwu__RatLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Rat.h"

class RatLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RatLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Rat);
    
};


#endif /* defined(__Miwu__RatLoader__) */
