//
//  WS1.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "WS1.h"

#define kCJStartSpeed 21
#define kCJHP 600
#define kCJATK 20
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool WS1::init()
{
    Enemy::init();
    effectSoundFileName = "jap_s1.wav";
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    
    return true;
}


float WS1::radius()
{
    return 25.0f;
}