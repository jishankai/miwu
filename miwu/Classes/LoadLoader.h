//
//  LoadLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__LoadLoader__
#define __miwu__LoadLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Load.h"

class LoadLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LoadLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Load);
    
};


#endif /* defined(__miwu__LoadLoader__) */
