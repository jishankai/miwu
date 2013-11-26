//
//  S1.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__S1__
#define __miwu__S1__

#include "Soldier.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#define kCJ_S1_BASE_HP 100
#define kCJ_S1_BASE_ATK 10
#define kCJ_S1_StartSpeed 60
#define kCJ_S1_ACTION_RANGE 1
#define kCJ_S1_ATK_DELAY 0.5
#define kCJ_S1_NORMAL_SKILL_RATE -1
#define kCJ_S1_HALO_SKILL_RATE 20

class S1 : public Soldier
{
    
private:
    bool init();
    virtual float getLv();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S1, create);
    
    virtual float radius();
    virtual void haloSkillHandler(GameObject* gameObject);
    virtual bool normalAtkTrigger();
};

#endif /* defined(__miwu__S1__) */
