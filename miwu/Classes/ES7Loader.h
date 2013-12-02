//
//  ES7Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__ES7Loader__
#define __miwu__ES7Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "ES7.h"

class ES7Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ES7Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ES7);
    
};


#endif /* defined(__miwu__ES7Loader__) */
