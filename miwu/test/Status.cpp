//
//  Status.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "Status.h"

#include "GameObject.h"
#include "MiaoInviteer.h"
#include "RBossInviteer.h"
#include "MouseNormalGameScene.h"
#include "Invite.h"
#include "GameOverScene.h"
#include "MainMouseMenuScene.h"

#include "Soldier.h"

#include "RS1Inviteer.h"
#include "RS2Inviteer.h"
#include "RS3Inviteer.h"
#include "RS4Inviteer.h"
#include "RS5Inviteer.h"
#include "RS6Inviteer.h"
#include "RS7Inviteer.h"
#include "RS8Inviteer.h"
#include "RS9Inviteer.h"
#include "RS10Inviteer.h"

#include "SimpleAudioEngine.h"

#define kCJScrollFilterFactor 0.1
#define kCJS1TargetOffset 156

USING_NS_CC;
USING_NS_CC_EXT;

void Status::onEnter()
{
    CCLayer::onEnter();
    
    // Schedule a selector that is called every frame
    this->scheduleUpdate();
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadInviteMusic("");
    
    _soldiers = new CCArray;
    _enimies = new CCArray;
    
    CCSprite* mBloodBar = CCSprite::createWithSpriteFrameName("blood_bar.png");
    miaoBloodBar = CCProgressTimer::create(mBloodBar);
    miaoBloodBar->setType(kCCProgressTimerTypeBar);
    miaoBloodBar->setMidpoint(CCPointZero);
    miaoBloodBar->setBarChangeRate(ccp(1.0f,0));
    miaoBloodBar->setPercentage(100);
    miaoBloodBar->setAnchorPoint(ccp(0,0.5f));
    miaoBloodBar->setPosition(ccp(43,24));
    
    CCSprite* bBloodBar = CCSprite::createWithSpriteFrameName("blood_bar.png");
    bossBloodBar = CCProgressTimer::create(bBloodBar);
    bossBloodBar->setType(kCCProgressTimerTypeBar);
    bossBloodBar->setMidpoint(ccp(1,1));
    bossBloodBar->setBarChangeRate(ccp(1.0f,0));
    bossBloodBar->setPercentage(100);
    bossBloodBar->setAnchorPoint(ccp(1,0.5f));
    bossBloodBar->setPosition(ccp(200,24));

    miao = (Miao*)MiaoInviteer::load();
    miao->setPosition(ccp(100,126));
    miao->bloodBar = miaoBloodBar;
    this->addChild(miao, 640-126);
    //_soldiers->addObject(miao);
    
    boss = (RBoss*)RBossInviteer::load();
    boss->setPosition(ccp(860,126));
    boss->setTag(200); //tag
    boss->bloodBar = bossBloodBar;
    this->addChild(boss,640-126);
    //_enimies->addObject(boss);
    
    this->getChildByTag(3)->addChild(miaoBloodBar);
    this->getChildByTag(4)->addChild(bossBloodBar);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playInviteMusic("background.mp3", true);
}

void Status::onExit()
{
    // Remove the scheduled selector
    this->unscheduleAllSelectors();
    
    _soldiers->release();
    _enimies->release();

    CCLayer::onExit();
}

SEL_MouseMenuHandler Status::onResolveCCBCCMouseMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedPelican:", Status::pressedPelican);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedBlood:", Status::pressedBlood);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedStone:", Status::pressedStone);
    
    return NULL;
}

SEL_CCControlHandler Status::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    return NULL;
}


bool Status::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool Status::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    return false;
}

void Status::update(float delta)
{
    miao->update(delta);
    MouseNormalGameScene* pMouseNormalGameScene = MouseNormalGameScene::sharedScene();
    Invite* pInvite = dynamic_cast<Invite*>(pMouseNormalGameScene->background);
    pInvite->update(delta);
    
    randTime += delta;
    if (randTime >= 5 and boss->getHp()>0) {
        randTime = 0;
        CCNode* enemy;
        int classType = rand()%10;
        switch (classType) {
            case 1:
                enemy = RS1Inviteer::load();
                enemy->setTag(201);
                break;
            case 2:
                enemy = RS2Inviteer::load();
                enemy->setTag(202);
                break;
            case 3:
                enemy = RS3Inviteer::load();
                enemy->setTag(203);
                break;
            case 4:
                enemy = RS4Inviteer::load();
                enemy->setTag(204);
                break;
            case 5:
                enemy = RS5Inviteer::load();
                enemy->setTag(205);
                break;
            case 6:
                enemy = RS6Inviteer::load();
                enemy->setTag(206);
                break;
            case 7:
                enemy = RS7Inviteer::load();
                enemy->setTag(207);
                break;
            case 8:
                enemy = RS8Inviteer::load();
                enemy->setTag(208);
                break;
            case 9:
                enemy = RS9Inviteer::load();
                enemy->setTag(209);
                break;
            case 0:
                enemy = RS10Inviteer::load();
                enemy->setTag(210);
                break;
            default:
                break;
        }
        
        // Determine where to spawn the target along the Y axis
        CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
        float minY = enemy->getContentSize().height/2+120;
        float maxY = winSize.height - 180 -  enemy->getContentSize().height/2;
        int rangeY = (int)(maxY - minY);
        // srand( TimGetTicks() );
        int actualY = ( rand() % rangeY ) + (int)minY;
        
        enemy->setPosition(ccp(960-enemy->getContentSize().width, CCDirector::sharedDirector()->getVisibleOrigin().y + actualY));
        this->addChild(enemy, 640-actualY);
        _enimies->addObject(enemy);
    }
    
    CCObject* st = NULL;
    CCARRAY_FOREACH(_soldiers, st)
    {
        Soldier* soldier = dynamic_cast<Soldier*>(st);
        soldier->update(delta);
        
        if (soldier->isS6) {
            CCObject* ct = NULL;
            CCARRAY_FOREACH(_soldiers, ct)
            {
                GameObject* sld = dynamic_cast<GameObject*>(ct);
                if (!soldier->getIsCollision() and ccpDistance(sld->getPosition(), soldier->getPosition()) < sld->radius() + soldier->radius()) {
                    soldier->handleCollisionWith(sld);
                    sld->handleCollisionWith(soldier);
                    
                    soldier->setIsCollision(true);
                }
            }
        }
    
        CCObject* et = NULL;
        CCARRAY_FOREACH(_enimies, et)
        {
            GameObject* enemy = dynamic_cast<GameObject*>(et);
            if (!soldier->getIsCollision() and !soldier->getIsCollision() and ccpDistance(enemy->getPosition(), soldier->getPosition()) < enemy->radius() + soldier->radius()) {
                soldier->setIsCollision(true);
                soldier->handleCollisionWith(enemy);
                break;
            }
            
        }
        
        // handle collision with boss
        if (!soldier->getIsScheduledForRemove() and !soldier->getIsCollision() and ccpDistance(boss->getPosition(), soldier->getPosition()) < boss->radius() + soldier->radius()) {
            boss->handleCollisionWith(soldier);
            soldier->handleCollisionWith(boss);
            
            soldier->setIsCollision(true);
        }
        
        if (!soldier->getIsCollision() and soldier->getXSpeed()==0) {
            soldier->resetSpeed();
        } else {
            soldier->setIsCollision(false);
        }
    }
    CCObject* et = NULL;
    CCARRAY_FOREACH(_enimies, et)
    {
        GameObject* enemy = dynamic_cast<GameObject*>(et);
        enemy->update(delta);
        
        CCObject* ct = NULL;
        CCARRAY_FOREACH(_soldiers, ct)
        {
            GameObject* sld = dynamic_cast<GameObject*>(ct);
            if (!enemy->getIsScheduledForRemove() and !enemy->getIsCollision() and ccpDistance(sld->getPosition(), enemy->getPosition()) < sld->radius() + enemy->radius()) {
                enemy->handleCollisionWith(sld);
                
                enemy->setIsCollision(true);
                break;
            } 
            if (sld->getIsScheduledForRemove()) {
                //sld->getBloodBar()->setVisible(false);
                /*
                CCActionInterval*  action = CCFadeOut::create(1.0f);
                sld->runAction(action);
                 */
                boss->setHp(boss->getHp()-10);
                this->removeChild(sld);
                _soldiers->removeObject(sld);
            }
            
        }
        
        // handle collision with miao
        if (!enemy->getIsScheduledForRemove() and !enemy->getIsCollision() and ccpDistance(miao->getPosition(), enemy->getPosition()) < miao->radius() + enemy->radius()) {
            miao->handleCollisionWith(enemy);
            enemy->handleCollisionWith(miao);
            
            enemy->setIsCollision(true);
        }
        if (miao->getIsScheduledForRemove()) {
            CCLOG("Game Over");
            CCScene* pScene = GameOverScene::scene();
            CCDirector::sharedDirector()->replaceScene(pScene);
            CocosDenshion::SimpleAudioEngine::sharedEngine()->stopInviteMusic(true);
        } else if (boss->getIsScheduledForRemove()) {
            CCLOG("Game Win");
            CCScene* pScene = MainMouseMenuScene::scene();
            CCDirector::sharedDirector()->replaceScene(pScene);
            CocosDenshion::SimpleAudioEngine::sharedEngine()->stopInviteMusic(true);
        }
        if (!enemy->getIsCollision() and enemy->getXSpeed()==0) {
            enemy->resetSpeed();
        } else {
            enemy->setIsCollision(false);
        }
        if (enemy->getIsScheduledForRemove()) {
            //enemy->getBloodBar()->setVisible(false);
            this->removeChild(enemy);
            _enimies->removeObject(enemy);
        }
    }
    
        /*
    // Iterate through all objects in the level layer
    CCObject* child = NULL;
    CCARRAY_FOREACH(this->m_pChildren, child)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(child);
        // Check if the child is a game object
        if (gameObject != NULL)
        {
            
            // Update all game objects
            gameObject->update(float delta);
            
            // Check for collisions with dragon
            if (gameObject == zombie)
            {
                S8* bear = dynamic_cast<S8*>(this->getChildByTag(101));
                if (bear!=NULL && ccpDistance(gameObject->getPosition(), bear->getPosition()) < gameObject->radius() + bear->radius())
                {
                    // Notify the game objects that they have collided
                    gameObject->handleCollisionWith(bear);
                    rabit->handleCollisionWith(gameObject);
                }
                
                if (ccpDistance(gameObject->getPosition(), rabit->getPosition()) < gameObject->radius() + rabit->radius())
                {
                    // Notify the game objects that they have collided
                    gameObject->handleCollisionWith(rabit);
                    rabit->handleCollisionWith(gameObject);
                }
            }
        }
    }
    
    // Check for objects to remove
    CCArray* gameObjectsToRemove = CCArray::create();
    CCARRAY_FOREACH(this->m_pChildren, child)
    {
        GameObject* gameObject = dynamic_cast<GameObject*>(child);
        if (gameObject != NULL)
        {
            
            if (gameObject->getIsScheduledForRemove())
            {
                gameObjectsToRemove->addObject(gameObject); 
            }
        }
    }
    
    GameObject* gameObject = NULL;
    for(int i = 0; i < gameObjectsToRemove->count(); i++)
    {
        gameObject = dynamic_cast<GameObject*>(gameObjectsToRemove->objectAtIndex(i));
        this->removeChild(gameObject, true);
    }*/
}

/*
void Status::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCInvite *pInvite)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    
    //cocos2d::CCNode* rabit = S1Inviteer::load();
    //rabit->setPosition(ccp(touchLocation.x, touchLocation.y));
    //this->addChild(rabit);
    cocos2d::CCNode* bear = S8Inviteer::load();
    bear->setPosition(ccp(touchLocation.x, touchLocation.y));
    bear->setTag(101);
    this->addChild(bear);

    //dragon->setXTarget(touchLocation.x);
}

void Status::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCInvite *pInvite)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    
    //dragon->setXTarget(touchLocation.x);
}
*/
void Status::pressedPelican(cocos2d::CCObject *pSender)
{
    CCLog("Use Pelicans");
}

void Status::pressedBlood(cocos2d::CCObject *pSender)
{
    CCLog("Use Blood");
}

void Status::pressedStone(cocos2d::CCObject *pSender)
{
    CCLog("Add Stone");
}
