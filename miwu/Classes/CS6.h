//
//  CS6.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__CS6__
#define __miwu__CS6__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class CS6 : public Enemy
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CS6, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__CS6__) */
