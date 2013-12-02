//
//  CS2.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__CS2__
#define __miwu__CS2__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class CS2 : public Enemy
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CS2, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__CS2__) */
