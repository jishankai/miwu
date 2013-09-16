//
//  S4.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S4.h"

#define kCJStartSpeed 21
#define kCJHP 400
#define kCJATK 20
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool S4::init()
{
    Soldier::init();
    effectSoundFileName = "s4_a1.wav";
    
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

float S4::radius()
{
    return 25.0f;
}
