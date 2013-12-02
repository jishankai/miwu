//
//  ES2Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__ES2Loader__
#define __miwu__ES2Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "ES2.h"

class ES2Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ES2Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ES2);
    
};


#endif /* defined(__miwu__ES2Loader__) */
