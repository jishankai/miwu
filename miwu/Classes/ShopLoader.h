//
//  ShopLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__ShopLoader__
#define __miwu__ShopLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Shop.h"

class ShopLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ShopLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Shop);
    
};


#endif /* defined(__miwu__ShopLoader__) */
