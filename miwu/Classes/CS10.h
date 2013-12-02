//
//  CS10.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__CS10__
#define __miwu__CS10__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class CS10 : public Enemy
{

private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CS10, create);
   
    virtual float radius();
};

#endif /* defined(__miwu__CS10__) */
