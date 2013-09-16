//
//  S4Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__S4Loader__
#define __miwu__S4Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "S4.h"

class S4Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(S4Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(S4);
    
};


#endif /* defined(__miwu__S4Loader__) */
