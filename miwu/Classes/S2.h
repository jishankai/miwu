//
//  S2.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__S2__
#define __miwu__S2__

#include "Soldier.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#define kCJ_S2_BASE_HP 60
#define kCJ_S2_BASE_ATK 30
#define kCJ_S2_StartSpeed 48
#define kCJ_S2_ACTION_RANGE 1
#define kCJ_S2_ATK_DELAY 1
#define kCJ_S2_NORMAL_SKILL_RATE -1
#define kCJ_S2_HALO_SKILL_RATE 20

class S2 : public Soldier
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S2, create);
    
    virtual float radius();
    virtual float getLv();
    virtual void haloSkillHandler(GameObject* gameObject);
    virtual bool normalAtkTrigger();
    void otherEnemyAtkHandler(GameObject* gameObject);
};

#endif /* defined(__miwu__S2__) */
