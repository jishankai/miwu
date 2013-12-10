//
//  Soldier.h
//  miwu
//
//  Created by Ji Shankai on 13-8-14.
//
//

#ifndef __miwu__Soldier__
#define __miwu__Soldier__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "GameObject.h"
#include "DrawLineLayer.h"

class Soldier : public GameObject
{  
public:
    virtual bool init();
    virtual void drawCollisionLine();
    virtual void onEnter();
    virtual void update(float delta, float width);
    virtual void update(float delta);
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual void resetSpeed();
    virtual bool isMaxHp();
    virtual float getLv();
    virtual void deadHandler();
    virtual bool normalSkillTrigger();
    virtual void normalSkillHandler(GameObject* gameObject);
    virtual bool haloSkillTrigger();
    virtual void haloSkillHandler(GameObject* gameObjetc);
    virtual bool normalAtkTrigger();
    void normalAtkHandler(GameObject* gameObject);
    virtual bool hurtToOther(float atk);
    virtual bool bearHurt();
    
    int normalSkillRate;
    int haloSkillRate;
    bool normalSkillTriggerResult;
    bool haloSkillTriggerResult;
    
private:
    DrawLineLayer *drawLineLayer;
};

#endif /* defined(__miwu__Soldier__) */
