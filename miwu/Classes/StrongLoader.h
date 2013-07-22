//
//  DinosaurLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__DinosaurLoader__
#define __Miwu__DinosaurLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Dinosaur.h"

class DinosaurLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(DinosaurLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Dinosaur);
    
};


#endif /* defined(__Miwu__DinosaurLoader__) */
