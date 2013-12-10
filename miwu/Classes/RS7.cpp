//
//  RS7.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "RS7.h"

#define kCJStartSpeed 21
#define kCJHP 600
#define kCJATK 20
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool RS7::init()
{
    Enemy::init();
    effectSoundFileName = "jap_s7.wav";
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    
    return true;
}


float RS7::radius()
{
    return 25.0f;
}

void RS7::reboundedHeartedHandler()
{
    this->atkHandler(0.1*maxHp, NULL);
}