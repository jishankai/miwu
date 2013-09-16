//
//  S2Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__S2Loader__
#define __miwu__S2Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "S2.h"

class S2Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(S2Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(S2);
    
};


#endif /* defined(__miwu__S2Loader__) */
