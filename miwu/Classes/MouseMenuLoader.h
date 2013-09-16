//
//  MouseMenuLoader.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__MouseMenuLoader__
#define __miwu__MouseMenuLoader__

#include "MouseMenu.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class MouseMenuLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MouseMenuLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MouseMenu);
    
};

#endif /* defined(__miwu__MouseMenuLoader__) */
