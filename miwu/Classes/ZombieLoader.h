//
//  ZombieLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__ZombieLoader__
#define __Miwu__ZombieLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Zombie.h"

class ZombieLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ZombieLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Zombie);
    
};


#endif /* defined(__Miwu__ZombieLoader__) */
