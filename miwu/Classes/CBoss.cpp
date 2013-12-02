//
//  CBoss.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "CBoss.h"
#include "Pause.h"
#include "PauseLoader.h"

#define kCJStartSpeed 0.5
#define kCJHP 200
#define kCJATK 10
#define kCJDEF 10

USING_NS_CC;
USING_NS_CC_EXT;


bool CBoss::init()
{
    xSpeed = kCJStartSpeed;
    hp = kCJHP;
    maxHp = kCJHP;
    atk = kCJATK;
    
//    bloodBar = CCSprite::createWithSpriteFrameName("blood_bar.png");
//    bloodBar->setScaleX(0.3);
//    bloodBar->setScaleY(0.5);
//    bloodBar->setAnchorPoint(ccp(0.5, 0));
    
    return true;
}

void CBoss::onEnter()
{
    GameObject::onEnter();
//    bloodBar->setPosition(ccp(0, this->getChildByTag(0)->getContentSize().height));
//    //bloodBar->setVisible(false);
//    this->addChild(bloodBar);
    
}

void CBoss::update(float delta)
{
    // Calculate new position
    CCPoint oldPosition = this->getPosition();
    
    float xNew = oldPosition.x - xSpeed*delta;
    this->setPosition(ccp(xNew, oldPosition.y));
}

void CBoss::drawCollisionLine()
{
    CCPoint start = ccp(this->getContentSize().width/2, 0);
    CCPoint end = ccp(this->getContentSize().width/2 - this->radius(), 0);
    drawLineLayer = DrawLineLayer::create(start, end);
    this->addChild(drawLineLayer);
}

void CBoss::handleCollisionWith(GameObject* gameObject)
{
//    if (this->hp<0) {
//        this->isScheduledForRemove = true;
//    }
//    
//    if (this->hp>=0 and gameObject != NULL) {
//        if (gameObject->getTag()<200) {
//            //xSpeed = 0;
//            //gameObject->setHp(gameObject->getHp()-this->getAtk());
//            //bloodBar->setPercentage(hp*100/maxHp);
//        }
//        
//    }
}

float CBoss::radius()
{
    return 25.0f;
}

void CBoss::resetSpeed()
{
    xSpeed = kCJStartSpeed;
}

bool CBoss::isMaxHp()
{
    return hp == maxHp;
}

void CBoss::deadHandler()
{
    CCLOG("Game Win");
    CCNode* pauseNode = PauseLoader::load();
    Pause* pause = dynamic_cast<Pause*>(pauseNode);
    pause->setAnchorPoint(CCPointZero);
    pause->setPosition(CCPointZero);
    pause->win->setVisible(true);
    this->addChild(pause);
    //            /*
    //            CCScene* pScene = MainMenuScene::scene();
    //            CCDirector::sharedDirector()->replaceScene(pScene);
    //             */
    //            CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
}

void CBoss::atkHandler(float atk)
{
    hp -= atk;
    if (hp <= 0)
    {
        deadHandler();
    }
}



