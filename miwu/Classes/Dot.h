//
//  Kangaroo.h
//  Miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __Miwu__Kangaroo__
#define __Miwu__Kangaroo__

#include "GameObject.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class Kangaroo : public GameObject
{

private:
    float xSpeed;
    
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Kangaroo, create);
    
    
    virtual void update();
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual float radius();
    virtual void attack();
    virtual void sAttack();
};

#endif /* defined(__Miwu__Kangaroo__) */
