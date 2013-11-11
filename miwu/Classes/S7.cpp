//
//  S7.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S7.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S7::init()
{
    Soldier::init();
    effectSoundFileName = "s7_a1.wav";
    
    xSpeed = kCJ_S7_StartSpeed;
    defaultSpeed = kCJ_S7_StartSpeed;
    hp = kCJ_S7_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S7_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    actionRange = kCJ_S7_ACTION_RANGE;
//    atkDelay = kCJ_S7_ATK_DELAY;
    
    return true;
}

float S7::radius()
{
    return 150+25.0f;
}

float S7::getLv()
{
    return 1.0f;
}