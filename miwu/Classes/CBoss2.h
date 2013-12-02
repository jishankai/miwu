//
//  CBoss2.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__CBoss2__
#define __miwu__CBoss2__

#include "GameObject.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#include "DrawLineLayer.h"

class CBoss2 : public GameObject
{

private:
    DrawLineLayer *drawLineLayer;
    bool init();
    void onEnter();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CBoss2, create);
    
    virtual void drawCollisionLine();
    virtual void update(float delta);
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual float radius();
    virtual void resetSpeed();
    virtual bool isMaxHp();
    virtual void deadHandler();
    virtual void atkHandler(float atk);
};

#endif /* defined(__miwu__CBoss2__) */
