//
//  S6.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "S6.h"
#include "Level.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool S6::init()
{
    Soldier::init();
    effectSoundFileName = "s6_a1.wav";    
    xSpeed = kCJ_S6_StartSpeed;
    defaultSpeed = kCJ_S6_StartSpeed;
    hp = kCJ_S6_BASE_HP*(1 + 5*(getLv() - 1)/100);
    maxHp = hp;
    atk = kCJ_S6_BASE_ATK*(1 + 5*(getLv() - 1)/100);
    actionRange = kCJ_S6_ACTION_RANGE;
//    atkDelay = kCJ_S6_ATK_DELAY;
    
    return true;
}

float S6::radius()
{
    return 150+25.0f;
}

float S6::getLv()
{
    return 1.0f;
}

void S6::handleCollisionWith(GameObject* gameObject)
{
    if (stopAction())
    {
        return;
    }
    
    Level* level = dynamic_cast<Level*>(this->getParent());
    CCObject* st = NULL;
    CCARRAY_FOREACH(level->_soldiers, st)
    {
        gameObject = dynamic_cast<GameObject*>(st);
        if (st != this and checkIsCollision(gameObject) and gameObject->isMaxHp() == false)
        {
            healHandler(gameObject);
        }
    }
    if (!this->isMaxHp() && !stopAction())
    {
        healHandler(this);
    }
}


void S6::healHandler(GameObject* gameObject)
{
    isCollision = true;
    stop();
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    if (animationManager->getRunningSequenceName() == NULL or strcmp(animationManager->getRunningSequenceName(), "attack1") != false)
    {
        animationManager->runAnimationsForSequenceNamed("attack1");
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(effectSoundFileName);
        gameObject->atkHandler(-atk);
    }
    curActionCount++;
}
