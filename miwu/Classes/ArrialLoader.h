//
//  PenguinLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__PenguinLoader__
#define __Miwu__PenguinLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Penguin.h"

class PenguinLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(PenguinLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Penguin);
    
};


#endif /* defined(__Miwu__PenguinLoader__) */
