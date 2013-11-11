//
//  Enemy.h
//  miwu
//
//  Created by Ji Shankai on 13-8-14.
//
//

#ifndef __miwu__Enemy__
#define __miwu__Enemy__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "GameObject.h"
#include "DrawLineLayer.h"

class Enemy : public GameObject
{
public:
    virtual bool init();
    virtual void drawCollisionLine();
    virtual void onEnter();
    virtual void update(float delta);
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual void resetSpeed();
    virtual bool isMaxHp();
    virtual void deadHandler();

private:
    DrawLineLayer *drawLineLayer;
};


#endif /* defined(__miwu__Enemy__) */
