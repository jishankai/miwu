//
//  S2.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S2.h"
#include "Level.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S2::init()
{
    Soldier::init();
    effectSoundFileName = "s2_a.wav";
    
    xSpeed = kCJ_S2_StartSpeed;
    defaultSpeed = kCJ_S2_StartSpeed;
    hp = kCJ_S2_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S2_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    actionRange = kCJ_S2_ACTION_RANGE;
//    atkDelay = kCJ_S2_ATK_DELAY;
    
    normalSkillRate = kCJ_S2_NORMAL_SKILL_RATE;
    haloSkillRate = kCJ_S2_HALO_SKILL_RATE;
    
    return true;
}

float S2::radius()
{
    return 150+25.0f;
}

float S2::getLv()
{
    return 1.0f;
}

void S2::haloSkillHandler(GameObject* gameObject)
{
    normalAtkHandler(gameObject);
//    otherEnemyAtkHandler(gameObject);
}

bool S2::normalAtkTrigger()
{
    return haloSkillTriggerResult == false;
}

void S2::otherEnemyAtkHandler(GameObject* gameObject)
{
    Level* level = dynamic_cast<Level*>(this->getParent());
    if (level == NULL)
    {
        return;
    }
    
    CCArray* enemies = level->_enimies;
    CCObject* et = NULL;
    CCARRAY_FOREACH(enemies, et)
    {
        GameObject* enemy = dynamic_cast<GameObject*>(et);
        if (enemy == NULL)
        {
            continue;
        }
        if (enemy != gameObject)
        {
            enemy->atkHandler(atk, this);
        }
    }
}
