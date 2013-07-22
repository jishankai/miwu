//
//  Rabit.h
//  Miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __Miwu__Rabit__
#define __Miwu__Rabit__

#include "GameObject.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class Rabit : public GameObject
{

private:
    float xSpeed;
    
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Rabit, create);
    
    
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual float radius();
    virtual void attack();
    virtual void sAttack();
};

#endif /* defined(__Miwu__Rabit__) */
