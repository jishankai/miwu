//
//  CS5.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "CS5.h"

#define kCJStartSpeed 30
#define kCJHP 150
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool CS5::init()
{
    Enemy::init();
    effectSoundFileName = "jap_s5.wav";
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    
    return true;
}


float CS5::radius()
{
    return 25.0f;
}