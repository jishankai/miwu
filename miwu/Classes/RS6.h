//
//  RS6.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__RS6__
#define __miwu__RS6__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class RS6 : public Enemy
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RS6, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__RS6__) */
