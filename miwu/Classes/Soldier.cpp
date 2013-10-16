//
//  Soldier.cpp
//  miwu
//
//  Created by Ji Shankai on 13-8-14.
//
//

#include "Soldier.h"
#include "SimpleAudioEngine.h"

#define kCJStartSpeed 60
#define kCJHP 200
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;

bool Soldier::init()
{
    isS6 = false;
    isS9 = false;
    
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    atk = kCJATK;
    def = kCJDEF;
    isCollision = false;
    
    bloodBar = CCSprite::createWithSpriteFrameName("blood_bar.png");
    bloodBar->setScaleX(0.3);
    bloodBar->setScaleY(0.5);
    bloodBar->setAnchorPoint(ccp(0.5, 0));    
    return true;
}

void Soldier::onEnter()
{
    GameObject::onEnter();
    bloodBar->setPosition(ccp(0, this->getChildByTag(0)->getContentSize().height));
    //bloodBar->setVisible(false);
    this->addChild(bloodBar);
}

void Soldier::update(float delta)
{}

void Soldier::update(float delta, float width)
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    if (oldPosition.x<width) {
        float xNew = oldPosition.x + xSpeed*delta;
        this->setPosition(ccp(xNew, oldPosition.y));
    }
}

void Soldier::handleCollisionWith(GameObject* gameObject)
{
    if (this->hp<=0) {
        this->isScheduledForRemove = true;
    }
    
    bloodBar->setScaleX(0.3f*hp/maxHp);
    
    if (gameObject != NULL) {
        if (gameObject->getTag()>=200) {
            if (ccpDistance(this->getPosition(), gameObject->getPosition())<=this->radius()) {
                xSpeed = 0;
            
            //this->setPositionX(this->getPositionX()-10);
            
            if (hp>0) {
                //bloodBar->setVisible(true);
                CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
                if (animationManager->getRunningSequenceName()==NULL or strcmp(animationManager->getRunningSequenceName(), "attack1")!=false) {
                    gameObject->setHp(gameObject->getHp()-this->getAtk());
                    //if (isS9) {
                        /*
                        if (strcmp(animationManager->getRunningSequenceName(), "attack2")!=false) {
                            animationManager->runAnimationsForSequenceNamed("attack2");
                        }
                         */
                    //} else {
                        animationManager->runAnimationsForSequenceNamed("attack1");
                    //}
                    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(effectSoundFileName);
                }
            }
            }
        } else {
            if (isS6) {
                if (!gameObject->isMaxHp()) {
                CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
                if (animationManager->getRunningSequenceName()==NULL or strcmp(animationManager->getRunningSequenceName(), "attack1")!=false) {
                    animationManager->runAnimationsForSequenceNamed("attack1");
                }
                }
            } else if (!this->isMaxHp()) {
                CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(gameObject->getUserObject());
                if (animationManager->getRunningSequenceName()==NULL or strcmp(animationManager->getRunningSequenceName(), "attack1")!=false) {
                    float newHp = this->getMaxHp()>(this->getHp()+gameObject->getAtk()) ? this->getHp()+gameObject->getAtk() : this->getMaxHp();
                    this->setHp(newHp);
                }
            }
        }
        
    }
}

void Soldier::resetSpeed()
{
    xSpeed = kCJStartSpeed;
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    animationManager->runAnimationsForSequenceNamed("walk");
}

bool Soldier::isMaxHp()
{
    return hp==maxHp;
}