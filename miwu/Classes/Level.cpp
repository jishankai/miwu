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
#include "LevelData.h"

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

#include "ES1Loader.h"
#include "ES2Loader.h"
#include "ES3Loader.h"
#include "ES4Loader.h"
#include "ES5Loader.h"
#include "ES6Loader.h"
#include "ES7Loader.h"
#include "ES8Loader.h"
#include "ES9Loader.h"
#include "ES10Loader.h"

#include "TS1Loader.h"
#include "TS2Loader.h"
#include "TS3Loader.h"
#include "TS4Loader.h"
#include "TS5Loader.h"
#include "TS6Loader.h"
#include "TS7Loader.h"
#include "TS8Loader.h"
#include "TS9Loader.h"
#include "TS10Loader.h"

#include "CS1Loader.h"
#include "CS2Loader.h"
#include "CS3Loader.h"
#include "CS4Loader.h"
#include "CS5Loader.h"
#include "CS6Loader.h"
#include "CS7Loader.h"
#include "CS8Loader.h"
#include "CS9Loader.h"
#include "CS10Loader.h"

#include "WS1Loader.h"
#include "WS2Loader.h"
#include "WS3Loader.h"
#include "WS4Loader.h"
#include "WS5Loader.h"
#include "WS6Loader.h"
#include "WS7Loader.h"
#include "WS8Loader.h"
#include "WS9Loader.h"
#include "WS10Loader.h"

#include "Pause.h"
#include "PauseLoader.h"
#include "Process.h"

#include "SimpleAudioEngine.h"
#include "Menu.h"

//#include <sstream>

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
    
    std::ostringstream s;
    s << Process::levelNum * Process::mapType;
    CCDictionary* _dict = LEVEL_DATA_DICT(s.str());
    _levelArray = (CCArray*)_dict->objectForKey('enemies');
    _level_hp = _dict->valueForKey('hp')->intValue();
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

    switch(Process::mapType) {
    case 1:
      if(Process::levelNum<=12) {
        _base_hp = 500;
        _boss_hp = 1000;
      } else {
        _base_hp = 625;
        _boss_hp = 1250;
      }
    case 2:
      if(Process::levelNum<=12) {
        _base_hp = 1200;
        _boss_hp = 2400;
      } else {
        _base_hp = 1500;
        _boss_hp = 3000;
      }
    case 1:
      if(Process::levelNum<=12) {
        _base_hp = 1900;
        _boss_hp = 3800;
      } else {
        _base_hp = 2375;
        _boss_hp = 4750;
      }
    case 1:
      if(Process::levelNum<=12) {
        _base_hp = 2600;
        _boss_hp = 5200;
      } else {
        _base_hp = 3250;
        _boss_hp = 6500;
      }
    case 1:
      if(Process::levelNum<=12) {
        _base_hp = 3300;
        _boss_hp = 6600;
      } else {
        _base_hp = 4125;
        _boss_hp = 8250;
      }

    }

    if (Process::levelNum%12==0) {
      _is_boss = true;
    }
    
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
    if ((_level_hp<=_level_hp*0.6 and _level_hp>_level_hp*0.5) or (_level_hp<=_level_hp*0.1 and _level_hp>0) or randTime >= 5) and boss->getHp()>0) {
        randTime = 0;
        CCNode* enemy;

        
        int classType = 0;
        bool isInLevel;
        do {
            if (classType==0 or classType==9) {
                classType = rand()%10;
            } else {
                if (classType <= 4) {
                    classType--;
                } else {
                    classType++;
                }
            }
            
            CCString *b = (CCString*)_levelArray->objectAtIndex(classType);
            isInLevel = b->boolValue();
        } while (!isInLevel);

        switch (Process::mapType) {
            case 1:
                switch (classType) {
                    case 0:
                        enemy = RS1Loader::load();
                        enemy->setTag(201);
                        break;
                    case 1:
                        enemy = RS2Loader::load();
                        enemy->setTag(202);
                        break;
                    case 2:
                        enemy = RS3Loader::load();
                        enemy->setTag(203);
                        break;
                    case 3:
                        enemy = RS4Loader::load();
                        enemy->setTag(204);
                        break;
                    case 4:
                        enemy = RS5Loader::load();
                        enemy->setTag(205);
                        break;
                    case 5:
                        enemy = RS6Loader::load();
                        enemy->setTag(206);
                        break;
                    case 6:
                        enemy = RS7Loader::load();
                        enemy->setTag(207);
                        break;
                    case 7:
                        enemy = RS8Loader::load();
                        enemy->setTag(208);
                        break;
                    case 8:
                        enemy = RS9Loader::load();
                        enemy->setTag(209);
                        break;
                    case 9:
                        enemy = RS10Loader::load();
                        enemy->setTag(210);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                switch (classType) {
                    case 0:
                        enemy = WS1Loader::load();
                        enemy->setTag(201);
                        break;
                    case 1:
                        enemy = WS2Loader::load();
                        enemy->setTag(202);
                        break;
                    case 2:
                        enemy = WS3Loader::load();
                        enemy->setTag(203);
                        break;
                    case 3:
                        enemy = WS4Loader::load();
                        enemy->setTag(204);
                        break;
                    case 4:
                        enemy = WS5Loader::load();
                        enemy->setTag(205);
                        break;
                    case 5:
                        enemy = WS6Loader::load();
                        enemy->setTag(206);
                        break;
                    case 6:
                        enemy = WS7Loader::load();
                        enemy->setTag(207);
                        break;
                    case 7:
                        enemy = WS8Loader::load();
                        enemy->setTag(208);
                        break;
                    case 8:
                        enemy = WS9Loader::load();
                        enemy->setTag(209);
                        break;
                    case 9:
                        enemy = WS10Loader::load();
                        enemy->setTag(210);
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                switch (classType) {
                    case 0:
                        enemy = TS1Loader::load();
                        enemy->setTag(201);
                        break;
                    case 1:
                        enemy = TS2Loader::load();
                        enemy->setTag(202);
                        break;
                    case 2:
                        enemy = TS3Loader::load();
                        enemy->setTag(203);
                        break;
                    case 3:
                        enemy = TS4Loader::load();
                        enemy->setTag(204);
                        break;
                    case 4:
                        enemy = TS5Loader::load();
                        enemy->setTag(205);
                        break;
                    case 5:
                        enemy = TS6Loader::load();
                        enemy->setTag(206);
                        break;
                    case 6:
                        enemy = TS7Loader::load();
                        enemy->setTag(207);
                        break;
                    case 7:
                        enemy = TS8Loader::load();
                        enemy->setTag(208);
                        break;
                    case 8:
                        enemy = TS9Loader::load();
                        enemy->setTag(209);
                        break;
                    case 9:
                        enemy = TS10Loader::load();
                        enemy->setTag(210);
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                switch (classType) {
                    case 0:
                        enemy = CS1Loader::load();
                        enemy->setTag(201);
                        break;
                    case 1:
                        enemy = CS2Loader::load();
                        enemy->setTag(202);
                        break;
                    case 2:
                        enemy = CS3Loader::load();
                        enemy->setTag(203);
                        break;
                    case 3:
                        enemy = CS4Loader::load();
                        enemy->setTag(204);
                        break;
                    case 4:
                        enemy = CS5Loader::load();
                        enemy->setTag(205);
                        break;
                    case 5:
                        enemy = CS6Loader::load();
                        enemy->setTag(206);
                        break;
                    case 6:
                        enemy = CS7Loader::load();
                        enemy->setTag(207);
                        break;
                    case 7:
                        enemy = CS8Loader::load();
                        enemy->setTag(208);
                        break;
                    case 8:
                        enemy = CS9Loader::load();
                        enemy->setTag(209);
                        break;
                    case 9:
                        enemy = CS10Loader::load();
                        enemy->setTag(210);
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                switch (classType) {
                    case 0:
                        enemy = ES1Loader::load();
                        enemy->setTag(201);
                        break;
                    case 1:
                        enemy = ES2Loader::load();
                        enemy->setTag(202);
                        break;
                    case 2:
                        enemy = ES3Loader::load();
                        enemy->setTag(203);
                        break;
                    case 3:
                        enemy = ES4Loader::load();
                        enemy->setTag(204);
                        break;
                    case 4:
                        enemy = ES5Loader::load();
                        enemy->setTag(205);
                        break;
                    case 5:
                        enemy = ES6Loader::load();
                        enemy->setTag(206);
                        break;
                    case 6:
                        enemy = ES7Loader::load();
                        enemy->setTag(207);
                        break;
                    case 7:
                        enemy = ES8Loader::load();
                        enemy->setTag(208);
                        break;
                    case 8:
                        enemy = ES9Loader::load();
                        enemy->setTag(209);
                        break;
                    case 9:
                        enemy = ES10Loader::load();
                        enemy->setTag(210);
                        break;
                    default:
                        break;
                }
                break;
                
            default:
                switch (classType) {
                    case 0:
                        enemy = RS1Loader::load();
                        enemy->setTag(201);
                        break;
                    case 1:
                        enemy = RS2Loader::load();
                        enemy->setTag(202);
                        break;
                    case 2:
                        enemy = RS3Loader::load();
                        enemy->setTag(203);
                        break;
                    case 3:
                        enemy = RS4Loader::load();
                        enemy->setTag(204);
                        break;
                    case 4:
                        enemy = RS5Loader::load();
                        enemy->setTag(205);
                        break;
                    case 5:
                        enemy = RS6Loader::load();
                        enemy->setTag(206);
                        break;
                    case 6:
                        enemy = RS7Loader::load();
                        enemy->setTag(207);
                        break;
                    case 7:
                        enemy = RS8Loader::load();
                        enemy->setTag(208);
                        break;
                    case 8:
                        enemy = RS9Loader::load();
                        enemy->setTag(209);
                        break;
                    case 9:
                        enemy = RS10Loader::load();
                        enemy->setTag(210);
                        break;
                    default:
                        break;
                }
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

        _level_hp-=enemy->getMaxHp();
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

    soldier_dead++;
}

void Level::removeEnemy(Enemy* enemy)
{
    _enimies->removeObject(enemy, true);
    if (this->getChildByTag(enemy->getTag()))
    {
        this->removeChild(enemy);
    }
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
