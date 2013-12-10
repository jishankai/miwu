//
//  RS4.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__RS4__
#define __miwu__RS4__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class RS4 : public Enemy
{
    
private:
    bool init();
    void reboundedHeartedHandler();
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RS4, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__RS4__) */
