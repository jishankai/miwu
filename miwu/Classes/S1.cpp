//
//  S1.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S1.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S1::init()
{
    Soldier::init();
    effectSoundFileName = "s1_a.wav";
    
    xSpeed = kCJ_S1_StartSpeed;
    defaultSpeed = kCJ_S1_StartSpeed;
    hp = kCJ_S1_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S1_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    actionRange = kCJ_S1_ACTION_RANGE;
//    atkDelay = kCJ_S1_ATK_DELAY;
    
    return true;
}

float S1::radius()
{
    return 25.0f;
}

float S1::getLv()
{
    return 1.0f;
}