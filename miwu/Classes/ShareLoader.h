//
//  ShareLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__ShareLoader__
#define __miwu__ShareLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Share.h"

class ShareLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ShareLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Share);
    
};


#endif /* defined(__miwu__ShareLoader__) */
