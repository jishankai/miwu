//
//  Enemy.cpp
//  miwu
//
//  Created by Ji Shankai on 13-8-14.
//
//

#include "Enemy.h"
#include "SimpleAudioEngine.h"
#include "StaticData.h"
#include "Level.h"

#define kCJStartSpeed 20
#define kCJHP 200
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool Enemy::init()
{
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    atk = kCJATK;
    isCollision = false;
    actionRange = 1;
    
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

void Enemy::drawCollisionLine()
{
    CCPoint start = ccp(this->getContentSize().width/2, 0);
    CCPoint end = ccp(this->getContentSize().width/2 - this->radius(), 0);
    drawLineLayer = DrawLineLayer::create(start, end);
    this->addChild(drawLineLayer);
}

void Enemy::onEnter()
{
    GameObject::onEnter();
        bloodBar->setPosition(ccp(0, this->getChildByTag(0)->getContentSize().height));
        //bloodBar->setVisible(false);
        this->addChild(bloodBar);

}

void Enemy::update(float delta)
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    if (oldPosition.x>0) {
        float xNew = oldPosition.x - xSpeed*delta;
        this->setPosition(ccp(xNew, oldPosition.y));
    }
}

void Enemy::handleCollisionWith(GameObject* gameObject)
{
//    if (this->hp<=0) {
//        this->isScheduledForRemove = true;
//    }
//    
//    bloodBar->setScaleX(0.3f*hp/maxHp);
//    
    if (gameObject != NULL)
    {
        if (gameObject->getTag() < 200)
        {
            if (stopAction())
            {
                return;
            }
            if (checkIsCollision(gameObject))
            {
                isCollision = true;
                stop();
                CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
                
                if (animationManager->getRunningSequenceName() == NULL or strcmp(animationManager->getRunningSequenceName(), "attack") != false)
                {
                    animationManager->runAnimationsForSequenceNamed("attack");
                    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(effectSoundFileName);
                    gameObject->atkHandler(atk);
                }
                curActionCount++;
            }
        }
        
    }    
}

void Enemy::resetSpeed()
{
    xSpeed = kCJStartSpeed;
    CCBAnimationManager* animationManager = dynamic_cast<CCBAnimationManager*>(this->getUserObject());
    if (animationManager->getRunningSequenceName() == NULL or strcmp(animationManager->getRunningSequenceName(), "walk") != false)
    {
        animationManager->runAnimationsForSequenceNamed("walk");
    }
}

bool Enemy::isMaxHp()
{
    return hp==maxHp;
}

void Enemy::deadHandler()
{
    Level* level = dynamic_cast<Level*>(this->getParent());
    level->removeEnemy(this);
}
