//
//  MedalLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__MedalLoader__
#define __miwu__MedalLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Medal.h"

class MedalLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MedalLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Medal);
    
};


#endif /* defined(__miwu__MedalLoader__) */
