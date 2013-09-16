//
//  StatusLoader.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__StatusLoader__
#define __miwu__StatusLoader__

#include "Status.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class StatusLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(StatusLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Status);
    
};

#endif /* defined(__miwu__StatusLoader__) */
