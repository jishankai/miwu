//
//  Level.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "Level.h"

#include "GameObject.h"
#include "MiaoLoader.h"
#include "RBossLoader.h"
#include "GameScene.h"
#include "Background.h"
#include "Status.h"
#include "GameOverScene.h"
#include "MainMenuScene.h"


#include "RS1Loader.h"
#include "RS2Loader.h"
#include "RS3Loader.h"
#include "RS4Loader.h"
#include "RS5Loader.h"
#include "RS6Loader.h"
#include "RS7Loader.h"
#include "RS8Loader.h"
#include "RS9Loader.h"
#include "RS10Loader.h"

#include "Pause.h"
#include "PauseLoader.h"

#include "SimpleAudioEngine.h"
#include "Menu.h"

#define kCJScrollFilterFactor 0.1
#define kCJS1TargetOffset 156

USING_NS_CC;
USING_NS_CC_EXT;

void Level::onEnter()
{
    CCLayer::onEnter();
    
    // Schedule a selector that is called every frame
    this->scheduleUpdate();
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("");
    
    _soldiers = new CCArray;
    _enimies = new CCArray;

    miao = (Miao*)MiaoLoader::load();
    miao->setPosition(ccp(100,126));
    //miao->bloodBar = miaoBloodBar;
    this->addChild(miao, 640-126);
    //_soldiers->addObject(miao);
    
    boss = (RBoss*)RBossLoader::load();
    boss->setPosition(ccp(860,126));
    boss->setTag(200); //tag
    //boss->bloodBar = bossBloodBar;
    this->addChild(boss,640-126);
    //_enimies->addObject(boss);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3", true);
}

void Level::onExit()
{
    // Remove the scheduled selector
    this->unscheduleAllSelectors();
    
    _soldiers->release();
    _enimies->release();

    CCLayer::onExit();
}

bool Level::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool Level::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    return false;
}

void Level::update(float delta)
{
    miao->update(delta);
    GameScene* pGameScene = GameScene::sharedScene();
    Background* pBackground = dynamic_cast<Background*>(pGameScene->background);
    Status* pStatus = dynamic_cast<Status*>(pGameScene->status);
    if (pStatus) {
        pStatus->miaoBloodBar->setPercentage(miao->getHp()*100/miao->getMaxHp());
        pStatus->bossBloodBar->setPercentage(boss->getHp()*100/boss->getMaxHp());
    }
    pBackground->update(delta);
    
    randTime += delta;
    //5
    if (randTime >= 5 and boss->getHp()>0) {
        randTime = 0;
        CCNode* enemy;
        int classType = rand()%10;
        switch (classType) {
            case 1:
                enemy = RS1Loader::load();
                enemy->setTag(201);
                break;
            case 2:
                enemy = RS2Loader::load();
                enemy->setTag(202);
                break;
            case 3:
                enemy = RS3Loader::load();
                enemy->setTag(203);
                break;
            case 4:
                enemy = RS4Loader::load();
                enemy->setTag(204);
                break;
            case 5:
                enemy = RS5Loader::load();
                enemy->setTag(205);
                break;
            case 6:
                enemy = RS6Loader::load();
                enemy->setTag(206);
                break;
            case 7:
                enemy = RS7Loader::load();
                enemy->setTag(207);
                break;
            case 8:
                enemy = RS8Loader::load();
                enemy->setTag(208);
                break;
            case 9:
                enemy = RS9Loader::load();
                enemy->setTag(209);
                break;
            case 0:
                enemy = RS10Loader::load();
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
        soldier->update(delta, 960);
        soldier->resetCurActionCount();
        soldier->setIsCollision(false);
        CCObject* et = NULL;
        CCARRAY_FOREACH(_enimies, et)
        {
            GameObject* enemy = dynamic_cast<GameObject*>(et);
            soldier->handleCollisionWith(enemy);
        }
        soldier->handleCollisionWith(NULL);
        
        // handle collision with boss
        soldier->handleCollisionWith(boss);
        if (!soldier->getIsCollision())
        {
            soldier->resetSpeed();
        }
    }
    
    CCObject* et = NULL;
    CCARRAY_FOREACH(_enimies, et)
    {
        GameObject* enemy = dynamic_cast<GameObject*>(et);
        enemy->update(delta);
        enemy->resetCurActionCount();
        enemy->setIsCollision(false);
        CCObject* ct = NULL;
        CCARRAY_FOREACH(_soldiers, ct)
        {
            GameObject* sld = dynamic_cast<GameObject*>(ct);
            //!enemy->getIsScheduledForRemove() and !enemy->getIsCollision() and
//            if (enemy->getPosition().x - sld->getPosition().x < enemy->radius())
//            {
            enemy->handleCollisionWith(sld);
//                enemy->setIsCollision(true);
//               // enemy->setIsCollision(true);
//                break;
//            } 
//            if (sld->getIsScheduledForRemove()) {
//                //sld->getBloodBar()->setVisible(false);
//                /*
//                CCActionInterval*  action = CCFadeOut::create(1.0f);
//                sld->runAction(action);
//                 */
//                boss->setHp(boss->getHp()-10);
//                this->removeChild(sld);
//                _soldiers->removeObject(sld);
//            }
            
        }
        
        enemy->handleCollisionWith(miao);
        if (!enemy->getIsCollision())
        {
            enemy->resetSpeed();
        }
        // handle collision with miao
//        if (!enemy->getIsScheduledForRemove() and !enemy->getIsCollision() and ccpDistance(miao->getPosition(), enemy->getPosition()) < miao->radius() + enemy->radius()) {
//            miao->handleCollisionWith(enemy);
//            enemy->handleCollisionWith(miao);
//            
//            enemy->setIsCollision(true);
//        }
//        if (miao->getIsScheduledForRemove()) {
//            CCLOG("Game Over");
//            CCScene* pScene = GameOverScene::scene();
//            CCDirector::sharedDirector()->replaceScene(pScene);
//            CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
//        } else if (boss->getIsScheduledForRemove()) {
//            CCLOG("Game Win");
//            CCNode* pauseNode = PauseLoader::load();
//            Pause* pause = dynamic_cast<Pause*>(pauseNode);
//            pause->setAnchorPoint(CCPointZero);
//            pause->setPosition(CCPointZero);
//            pause->win->setVisible(true);
//            this->addChild(pause);
//            /*
//            CCScene* pScene = MainMenuScene::scene();
//            CCDirector::sharedDirector()->replaceScene(pScene);
//             */
//            CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
//        }
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

void Level::removeSoldier(Soldier *soldier)
{
    if (this->getChildByTag(soldier->getTag()))
    {
        this->removeChild(soldier);
    }
    
    _soldiers->removeObject(soldier, true);
    soldier = NULL;
}

void Level::removeEnemy(Enemy* enemy)
{
    if (this->getChildByTag(enemy->getTag()))
    {
        this->removeChild(enemy);
    }
    
    _enimies->removeObject(enemy, true);
    enemy = NULL;
}

void Level::winHandler()
{
    GameScene* gameScene = GameScene::sharedScene();
    dynamic_cast<Menu*>(gameScene->menu)->winHandler();
}

void Level::loseHandler()
{
    CCScene* pScene = GameOverScene::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
    CCDirector::sharedDirector()->pause();
}
/*
void Level::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    
    //cocos2d::CCNode* rabit = S1Loader::load();
    //rabit->setPosition(ccp(touchLocation.x, touchLocation.y));
    //this->addChild(rabit);
    cocos2d::CCNode* bear = S8Loader::load();
    bear->setPosition(ccp(touchLocation.x, touchLocation.y));
    bear->setTag(101);
    this->addChild(bear);

    //dragon->setXTarget(touchLocation.x);
}

void Level::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    
    //dragon->setXTarget(touchLocation.x);
}
*/