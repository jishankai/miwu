//
//  MonkeyLoader.h
//  Miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __Miwu__MonkeyLoader__
#define __Miwu__MonkeyLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Monkey.h"

class MonkeyLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MonkeyLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Monkey);
    
};


#endif /* defined(__Miwu__MonkeyLoader__) */
