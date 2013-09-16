//
//  S3.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S3.h"

#define kCJStartSpeed 45
#define kCJHP 100
#define kCJATK 20
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool S3::init()
{
    Soldier::init();
    effectSoundFileName = "s3_a1.wav";
    
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

float S3::radius()
{
    return 25.0f;
}
