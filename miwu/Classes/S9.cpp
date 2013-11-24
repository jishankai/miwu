//
//  S9.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S9.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S9::init()
{
    Soldier::init();
    effectSoundFileName = "s9_a1.wav";
    
    xSpeed = kCJ_S9_StartSpeed;
    defaultSpeed = kCJ_S9_StartSpeed;
    hp = kCJ_S9_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S9_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    actionRange = kCJ_S9_ACTION_RANGE;
    
    normalSkillRate = kCJ_S9_NORMAL_SKILL_RATE;
    haloSkillRate = kCJ_S9_HALO_SKILL_RATE;
//    atkDelay = kCJ_S9_ATK_DELAY;
    
    return true;
}

float S9::radius()
{
    return 1+25.0f;
}

float S9::getLv()
{
    return 1.0f;
}
