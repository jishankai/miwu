//
//  ES1.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__ES1__
#define __miwu__ES1__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class ES1 : public Enemy
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ES1, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__ES1__) */
