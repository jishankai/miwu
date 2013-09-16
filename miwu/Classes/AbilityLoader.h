//
//  AbilityLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__AbilityLoader__
#define __miwu__AbilityLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Ability.h"

class AbilityLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AbilityLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Ability);
    
};


#endif /* defined(__miwu__AbilityLoader__) */
