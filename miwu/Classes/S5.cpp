//
//  S5.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S5.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S5::init()
{
    Soldier::init();
    effectSoundFileName = "s5_a1.wav";
    
    xSpeed = kCJ_S5_StartSpeed;
    defaultSpeed = kCJ_S5_StartSpeed;
    hp = kCJ_S5_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S5_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    actionRange = kCJ_S5_ACTION_RANGE;
    
    normalSkillRate = kCJ_S5_NORMAL_SKILL_RATE;
    haloSkillRate = kCJ_S5_HALO_SKILL_RATE;
//    atkDelay = kCJ_S5_ATK_DELAY;
    
    return true;
}

float S5::radius()
{
    return 1+25.0f;
}

float S5::getLv()
{
    return 1.0f;
}
