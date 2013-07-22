//
//  RhinocerosLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__RhinocerosLoader__
#define __Miwu__RhinocerosLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Rhinoceros.h"

class RhinocerosLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RhinocerosLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Rhinoceros);
    
};


#endif /* defined(__Miwu__RhinocerosLoader__) */
