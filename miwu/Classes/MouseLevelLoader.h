//
//  MouseLevelLoader.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__MouseLevelLoader__
#define __miwu__MouseLevelLoader__

#include "MouseLevel.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class MouseLevelLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MouseLevelLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MouseLevel);
    
};

#endif /* defined(__miwu__MouseLevelLoader__) */
