//
//  ArmyLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__ArmyLoader__
#define __miwu__ArmyLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Army.h"

class ArmyLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ArmyLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Army);
    
};


#endif /* defined(__miwu__ArmyLoader__) */
