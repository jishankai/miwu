//
//  EventLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__EventLoader__
#define __miwu__EventLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Event.h"

class EventLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(EventLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Event);
    
};


#endif /* defined(__miwu__EventLoader__) */
