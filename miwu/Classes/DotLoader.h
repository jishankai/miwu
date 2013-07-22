//
//  KangarooLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__KangarooLoader__
#define __Miwu__KangarooLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Kangaroo.h"

class KangarooLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(KangarooLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Kangaroo);
    
};


#endif /* defined(__Miwu__KangarooLoader__) */
