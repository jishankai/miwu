//
//  MenuLoader.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__MenuLoader__
#define __miwu__MenuLoader__

#include "Menu.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class MenuLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Menu);
    
};

#endif /* defined(__miwu__MenuLoader__) */
