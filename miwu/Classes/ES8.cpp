//
//  ES8.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "ES8.h"

#define kCJStartSpeed 24
#define kCJHP 60
#define kCJATK 30
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool ES8::init()
{
    Enemy::init();
    effectSoundFileName = "jap_s8.wav";
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    
    return true;
}


float ES8::radius()
{
    return 100+25.0f;
}