//
//  CS3Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__CS3Loader__
#define __miwu__CS3Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "CS3.h"

class CS3Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CS3Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CS3);
    
};


#endif /* defined(__miwu__CS3Loader__) */
