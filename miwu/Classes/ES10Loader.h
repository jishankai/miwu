//
//  ES10Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__ES10Loader__
#define __miwu__ES10Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "ES10.h"

class ES10Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ES10Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ES10);
    
};


#endif /* defined(__miwu__ES10Loader__) */
