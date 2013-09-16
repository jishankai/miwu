//
//  S2.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S2.h"

#define kCJStartSpeed 24
#define kCJHP 60
#define kCJATK 30
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool S2::init()
{
    Soldier::init();
    effectSoundFileName = "s2_a.wav";
    
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

float S2::radius()
{
    return 150+25.0f;
}
