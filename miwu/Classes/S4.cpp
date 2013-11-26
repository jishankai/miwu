//
//  S4.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S4.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S4::init()
{
    Soldier::init();
    effectSoundFileName = "s4_a1.wav";
    
    xSpeed = kCJ_S4_StartSpeed;
    defaultSpeed = kCJ_S4_StartSpeed;
    hp = kCJ_S4_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S4_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    actionRange = kCJ_S4_ACTION_RANGE;
    
    normalSkillRate = kCJ_S4_NORMAL_SKILL_RATE;
    haloSkillRate = kCJ_S4_HALO_SKILL_RATE;
//    atkDelay = kCJ_S4_ATK_DELAY;
    
    return true;
}

float S4::radius()
{
    return 25.0f;
}

float S4::getLv()
{
    return 1.0f;
}
