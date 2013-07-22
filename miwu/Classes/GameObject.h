//
//  GameObject.h
//  Miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __Miwu__GameObject__
#define __Miwu__GameObject__

#include "cocos2d.h"

class GameObject : public cocos2d::CCNode
{
    
public:
    CC_SYNTHESIZE(bool, isScheduledForRemove, IsScheduledForRemove);
    CC_SYNTHESIZE(float, atk, Atk);
    CC_SYNTHESIZE(float, def, Def);
    CC_SYNTHESIZE(float, hp, Hp);
    
    virtual float radius() = 0;
    virtual void update() = 0;
    virtual void handleCollisionWith(GameObject* gameObject) = 0;
    virtual void attack() = 0;
    virtual void sAttack() = 0;
};

#endif /* defined(__Miwu__GameObject__) */
