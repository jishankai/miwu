//
//  TS8.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__TS8__
#define __miwu__TS8__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class TS8 : public Enemy
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(TS8, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__TS8__) */
