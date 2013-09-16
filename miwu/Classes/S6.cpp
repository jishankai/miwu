//
//  S6.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S6.h"

#define kCJStartSpeed 30
#define kCJHP 180
#define kCJATK 20
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool S6::init()
{
    Soldier::init();
    effectSoundFileName = "s6_a1.wav";
    isS6 = true;
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

float S6::radius()
{
    return 150+25.0f;
}
