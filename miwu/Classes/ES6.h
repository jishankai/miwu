//
//  ES6.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__ES6__
#define __miwu__ES6__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class ES6 : public Enemy
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ES6, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__ES6__) */
