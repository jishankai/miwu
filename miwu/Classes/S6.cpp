//
//  S6.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S6.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S6::init()
{
    Soldier::init();
    effectSoundFileName = "s6_a1.wav";
    isS6 = true;
    
    xSpeed = kCJ_S6_StartSpeed;
    defaultSpeed = kCJ_S6_StartSpeed;
    hp = kCJ_S6_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S6_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    def = kCJ_S6_DEF;
    
    return true;
}

float S6::radius()
{
    return 150+25.0f;
}

float S6::getLv()
{
    return 1.0f;
}
