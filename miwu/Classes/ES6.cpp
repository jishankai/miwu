//
//  ES6.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "ES6.h"

#define kCJStartSpeed 30
#define kCJHP 150
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool ES6::init()
{
    Enemy::init();
    effectSoundFileName = "jap_s6.wav";
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    
    return true;
}


float ES6::radius()
{
    return 25.0f;
}