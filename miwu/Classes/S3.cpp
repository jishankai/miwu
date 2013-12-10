//
//  S3.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S3.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S3::init()
{
    Soldier::init();
    effectSoundFileName = "s3_a1.wav";
    
    xSpeed = kCJ_S3_StartSpeed;
    defaultSpeed = kCJ_S3_StartSpeed;
    hp = kCJ_S3_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S3_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    actionRange = kCJ_S3_ACTION_RANGE;
//    atkDelay = kCJ_S3_ATK_DELAY;
    
    normalSkillRate = kCJ_S3_NORMAL_SKILL_RATE;
    haloSkillRate = kCJ_S3_HALO_SKILL_RATE;
    
    return true;
}

float S3::radius()
{
    return 25.0f;
}

float S3::getLv()
{
    return 1.0f;
}

void S3::reboundHeartHandler(GameObject* gameObject)
{
    if (gameObject == NULL)
    {
        return;
    }
    
    if (haloSkillTrigger())
    {
        gameObject->reboundedHeartedHandler();
    }
}


