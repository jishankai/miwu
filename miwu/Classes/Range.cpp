//
//  Monkey.cpp
//  Miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "Monkey.h"

#include "Zombie.h"
#include "GameScene.h"


#define kCJStartSpeed 0.5
#define kCJHP 200
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool Monkey::init()
{
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    
    return true;
}

void Monkey::update()
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    float xNew = oldPosition.x + xSpeed;
    this->setPosition(ccp(xNew, oldPosition.y));
}

void Monkey::handleCollisionWith(GameObject* gameObject)
{
    if (this->hp<=0) {
        this->isScheduledForRemove = true;
    }
    Zombie* zombie = dynamic_cast<Zombie*>(gameObject);
    
    
    if (zombie != NULL) {
        //xSpeed = 0;
        this->setPositionX(this->getPositionX()-10);
        zombie->setHp(zombie->getHp()-this->atk);
        CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
        animationManager->runAnimationsForSequenceNamed("attack");
    }
}

void Monkey::attack()
{}

void Monkey::sAttack()
{}

float Monkey::radius()
{
    return 25.0f;
}
