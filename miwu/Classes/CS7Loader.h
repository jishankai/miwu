//
//  CS7Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__CS7Loader__
#define __miwu__CS7Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "CS7.h"

class CS7Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CS7Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CS7);
    
};


#endif /* defined(__miwu__CS7Loader__) */
