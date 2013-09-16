//
//  MiaoLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__MiaoLoader__
#define __miwu__MiaoLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Miao.h"

class MiaoLoader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MiaoLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Miao);
    
};


#endif /* defined(__miwu__MiaoLoader__) */
