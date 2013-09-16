//
//  Miao.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "Miao.h"

#define kCJStartSpeed 0
#define kCJHP 200
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool Miao::init()
{
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    isCollision = false;
    
    return true;
}

bool Miao::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "miaoSprite", CCSprite*, this->miaoSprite);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "circleSprite", CCSprite*, this->circleSprite);
    
    return false;
}

void Miao::update(float delta)
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    if (oldPosition.x>0 and oldPosition.x<960) {
        float xNew = oldPosition.x + xSpeed*delta;
        this->setPosition(ccp(xNew, oldPosition.y));
    }
}

void Miao::handleCollisionWith(GameObject* gameObject)
{
    if (this->hp<0) {
        this->isScheduledForRemove = true;
    }
    
    if (this->hp>=0 and gameObject != NULL) {
        if (gameObject->getTag()>200) {
            //xSpeed = 0;
            //gameObject->setHp(gameObject->getHp()-this->getAtk());
            //bloodBar->setPercentage(hp*100/maxHp);
        }
        
    }
}

float Miao::radius()
{
    return 25.0f;
}

void Miao::resetSpeed()
{
    xSpeed = kCJStartSpeed;
}

bool Miao::isMaxHp()
{
    return hp==maxHp;
}