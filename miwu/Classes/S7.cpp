//
//  S7.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S7.h"

#define kCJStartSpeed 21
#define kCJHP 150
#define kCJATK 60
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool S7::init()
{
    Soldier::init();
    effectSoundFileName = "s7_a1.wav";
    
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

float S7::radius()
{
    return 150+25.0f;
}
