//
//  S8.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S8.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S8::init()
{
    Soldier::init();
    effectSoundFileName = "s8_a1.wav";
    
    xSpeed = kCJ_S8_StartSpeed;
    defaultSpeed = kCJ_S8_StartSpeed;
    hp = kCJ_S8_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S8_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    def = kCJ_S8_DEF;
    
    return true;
}

float S8::radius()
{
    return 150+25.0f;
}

float S8::getLv()
{
    return 1.0f;
}
