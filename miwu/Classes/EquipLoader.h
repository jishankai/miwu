//
//  EquipLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__EquipLoader__
#define __miwu__EquipLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Equip.h"

class EquipLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(EquipLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Equip);
    
};


#endif /* defined(__miwu__EquipLoader__) */
