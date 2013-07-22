//
//  BackgroundLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __Miwu__BackgroundLoader__
#define __Miwu__BackgroundLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Background.h"

class BackgroundLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BackgroundLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Background);
    
};


#endif /* defined(__Miwu__BackgroundLoader__) */
