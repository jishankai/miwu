//
//  BaseLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__BaseLoader__
#define __miwu__BaseLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Base.h"

class BaseLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BaseLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Base);
    
};


#endif /* defined(__miwu__BaseLoader__) */
