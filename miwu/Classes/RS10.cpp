//
//  RS10.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "RS10.h"

#define kCJStartSpeed 30
#define kCJHP 100
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool RS10::init()
{
    Enemy::init();
    effectSoundFileName = "jap_s10.wav";
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}


float RS10::radius()
{
    return 25.0f;
}
