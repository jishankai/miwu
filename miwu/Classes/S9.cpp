//
//  S9.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S9.h"

#define kCJStartSpeed 24
#define kCJHP 400
#define kCJATK 50
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool S9::init()
{
    Soldier::init();
    effectSoundFileName = "s9_a1.wav";
    isS9 = true;
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

float S9::radius()
{
    return 1+25.0f;
}
