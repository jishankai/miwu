//
//  WS2.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__WS2__
#define __miwu__WS2__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class WS2 : public Enemy
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(WS2, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__WS2__) */
