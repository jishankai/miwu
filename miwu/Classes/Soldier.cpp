//
//  Soldier.cpp
//  miwu
//
//  Created by Ji Shankai on 13-8-14.
//
//

#include "Soldier.h"
#include "SimpleAudioEngine.h"
#include "StaticData.h"
#include "Level.h"

USING_NS_CC;
USING_NS_CC_EXT;

bool Soldier::init()
{
    //isS6 = false;
    //isS9 = false;
    
//    isScheduledForRemove = false;
    isCollision = false;
    curActionCount = 0;
//    delayCount = 0;
    
    bloodBar = CCSprite::createWithSpriteFrameName("blood_bar.png");
    bloodBar->setScaleX(0.3);
    bloodBar->setScaleY(0.5);
    bloodBar->setAnchorPoint(ccp(0.5, 0));
    
    if (STATIC_DATA_INT("debug") == 1)
    {
        drawCollisionLine();
    }
    return true;
}

void Soldier::onEnter()
{
    GameObject::onEnter();
    bloodBar->setPosition(ccp(0, this->getChildByTag(0)->getContentSize().height));
    //bloodBar->setVisible(false);
    this->addChild(bloodBar);
}

void Soldier::drawCollisionLine()
{
    CCPoint start = ccp(this->getContentSize().width/2, 0);
    CCPoint end = ccp(this->getContentSize().width/2 + this->radius(), 0);
    drawLineLayer = DrawLineLayer::create(start, end);
    this->addChild(drawLineLayer);
}

void Soldier::update(float delta)
{}

void Soldier::update(float delta, float width)
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    if (oldPosition.x<width) {
        float xNew = oldPosition.x + xSpeed*delta/3;
        this->setPosition(ccp(xNew, oldPosition.y));
    }
}

void Soldier::handleCollisionWith(GameObject* gameObject)
{
//    if (this->hp<=0) {
//        this->isScheduledForRemove = true;
//    }
//    
//    bloodBar->setScaleX(0.3f*hp/maxHp);
    
    if (gameObject != NULL)
    {
        if (gameObject->getTag() >= 200)
        {
           // if (ccpDistance(this->getPosition(), gameObject->getPosition())<=this->radius()) {
            if (stopAction())
            {
                return;
            }
            if (checkIsCollision(gameObject))
            {
                isCollision = true;
                stop();
                if (normalSkillTrigger())
                {
                    normalSkillHandler(gameObject);
                }
                
                if (haloSkillTrigger())
                {
                    haloSkillHandler(gameObject);
                }
                
                if (normalAtkTrigger())
                {
                    normalAtkHandler(gameObject);
                }
                
                curActionCount++;
            }
            
            //this->setPositionX(this->getPositionX()-10);
            
//            if (hp>0) {
                //bloodBar->setVisible(true);
                
//                 {
//                    gameObject->setHp(gameObject->getHp()-this->getAtk());
                    //if (isS9) {
                        /*
                        if (strcmp(animationManager->getRunningSequenceName(), "attack2")!=false) {
                            animationManager->runAnimationsForSequenceNamed("attack2");
                        }
                         */
                    //} else {
                     
                    //}
                    
//                }
            //}
//            }
//        } else {
//            if (isS6) {
//                if (!gameObject->isMaxHp()) {
//                CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
//                if (animationManager->getRunningSequenceName()==NULL or strcmp(animationManager->getRunningSequenceName(), "attack1")!=false) {
//                    animationManager->runAnimationsForSequenceNamed("attack1");
//                }
//                }
//            } else if (!this->isMaxHp()) {
//                CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(gameObject->getUserObject());
//                if (animationManager->getRunningSequenceName()==NULL or strcmp(animationManager->getRunningSequenceName(), "attack1")!=false) {
//                    float newHp = this->getMaxHp()>(this->getHp()+gameObject->getAtk()) ? this->getHp()+gameObject->getAtk() : this->getMaxHp();
//                    this->setHp(newHp);
//                }
//            }
        }
        
    }
}

void Soldier::resetSpeed()
{
    xSpeed = defaultSpeed;
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    if (animationManager->getRunningSequenceName() == NULL or strcmp(animationManager->getRunningSequenceName(), "walk") != false)
    {
        animationManager->runAnimationsForSequenceNamed("walk");
    }
}

bool Soldier::isMaxHp()
{
    return hp == maxHp;
}

float Soldier::getLv()
{
    return 1.0f;
}

void Soldier::deadHandler()
{
    Level* level = dynamic_cast<Level*>(this->getParent());
    level->removeSoldier(this);
}

bool Soldier::normalSkillTrigger()
{
    float randValue = CCRANDOM_0_1()*100;
    normalSkillTriggerResult = randValue >= 0 && randValue < normalSkillRate;
    return normalSkillTriggerResult;
}

void Soldier::normalSkillHandler(GameObject* gameObject)
{
    
}

bool Soldier::haloSkillTrigger()
{
    Level* level = dynamic_cast<Level*>(this->getParent());
    if (level == NULL)
    {
        return false;
    }
    
    Miao* miao = level->miao;
    if (miao == NULL)
    {
        return false;
    }
    
    float distance = abs(miao->getPositionY() - this->getPositionY());
    if (miao->getHaloRadius() < distance)
    {
        return false;
    }
    
    float randValue = CCRANDOM_0_1()*100;
    haloSkillTriggerResult = randValue >= 0 && randValue < haloSkillRate;
    return haloSkillTriggerResult;
}

void Soldier::haloSkillHandler(GameObject* gameObject)
{
    
}

bool Soldier::normalAtkTrigger()
{
    return false;
}

void  Soldier::normalAtkHandler(GameObject* gameObject)
{
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    if (animationManager->getRunningSequenceName() == NULL or strcmp(animationManager->getRunningSequenceName(), "attack1") != false)
    {
        animationManager->runAnimationsForSequenceNamed("attack1");
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(effectSoundFileName);
        gameObject->atkHandler(atk);
    }
}



