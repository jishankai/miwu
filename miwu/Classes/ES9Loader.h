//
//  ES9Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__ES9Loader__
#define __miwu__ES9Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "ES9.h"

class ES9Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ES9Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ES9);
    
};


#endif /* defined(__miwu__ES9Loader__) */
