//
//  OthersLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__OthersLoader__
#define __miwu__OthersLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Others.h"

class OthersLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OthersLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Others);
    
};


#endif /* defined(__miwu__OthersLoader__) */
