//
//  ES8Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__ES8Loader__
#define __miwu__ES8Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "ES8.h"

class ES8Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ES8Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ES8);
    
};


#endif /* defined(__miwu__ES8Loader__) */
