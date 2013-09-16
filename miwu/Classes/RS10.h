//
//  RS10.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__RS10__
#define __miwu__RS10__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class RS10 : public Enemy
{

private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RS10, create);
   
    virtual float radius();
};

#endif /* defined(__miwu__RS10__) */
