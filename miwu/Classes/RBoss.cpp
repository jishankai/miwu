//
//  RBoss.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "RBoss.h"

#define kCJStartSpeed 0.5
#define kCJHP 200
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool RBoss::init()
{
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

void RBoss::update(float delta)
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    float xNew = oldPosition.x - xSpeed*delta;
    this->setPosition(ccp(xNew, oldPosition.y));
}

void RBoss::handleCollisionWith(GameObject* gameObject)
{
    if (this->hp<0) {
        this->isScheduledForRemove = true;
    }
    
    if (this->hp>=0 and gameObject != NULL) {
        if (gameObject->getTag()<200) {
            //xSpeed = 0;
            //gameObject->setHp(gameObject->getHp()-this->getAtk());
            //bloodBar->setPercentage(hp*100/maxHp);
        }
        
    }
}

float RBoss::radius()
{
    return 25.0f;
}

void RBoss::resetSpeed()
{
    xSpeed = kCJStartSpeed;
}

bool RBoss::isMaxHp()
{
    return hp==maxHp;
}