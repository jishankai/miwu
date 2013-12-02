//
//  CS9Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__CS9Loader__
#define __miwu__CS9Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "CS9.h"

class CS9Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CS9Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CS9);
    
};


#endif /* defined(__miwu__CS9Loader__) */
