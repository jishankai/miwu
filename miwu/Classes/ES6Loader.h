//
//  ES6Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__ES6Loader__
#define __miwu__ES6Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "ES6.h"

class ES6Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ES6Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ES6);
    
};


#endif /* defined(__miwu__ES6Loader__) */
