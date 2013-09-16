//
//  S5.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S5.h"

#define kCJStartSpeed 30
#define kCJHP 150
#define kCJATK 20
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool S5::init()
{
    Soldier::init();
    effectSoundFileName = "s5_a1.wav";
    
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

float S5::radius()
{
    return 1+25.0f;
}
