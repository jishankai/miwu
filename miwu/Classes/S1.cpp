//
//  S1.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S1.h"

#define kCJStartSpeed 30
#define kCJHP 100
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool S1::init()
{
    Soldier::init();
    effectSoundFileName = "s1_a.wav";
    
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

float S1::radius()
{
    return 25.0f;
}