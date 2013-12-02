//
//  Process.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Process.h"

#include "cocos2d.h"
#include "ProcessLoader.h"

#include "NormalGameScene.h"
#include "MouseGameScene.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
USING_NS_CC_EXT;

int Process::mapType = 1;
int Process::levelNum = 1;

void Process::onEnter()
{
    //this->url = "http://localhost/~jishankai/miwu/index.php?r=user/loginApi";
    //this->requestApi();
    
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
}

bool Process::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_ri", CCSprite*, this->level_ri);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_west", CCSprite*, this->level_west);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_tale", CCSprite*, this->level_tale);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_cn", CCSprite*, this->level_cn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level_evil", CCSprite*, this->level_evil);
    
    return false;
}

bool Process::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(4, 280, 32, 16);
    CCRect* pGameTextureRect = new CCRect(410, 280, 32, 16);
    CCRect* pLevel1Rect = new CCRect(72, 186.5, 48, 38.4);
    CCRect* pLevel2Rect = new CCRect(130.5, 186.5, 48, 38.4);
    CCRect* pLevel3Rect = new CCRect(189, 186.5, 48, 38.4);
    CCRect* pLevel4Rect = new CCRect(247.5, 186.5, 48, 38.4);
    CCRect* pLevel5Rect = new CCRect(306, 186.5, 48, 38.4);
    CCRect* pLevel6Rect = new CCRect(364.5, 186.5, 48, 38.4);
    CCRect* pLevel7Rect = new CCRect(72, 132, 48, 38.4);
    CCRect* pLevel8Rect = new CCRect(130.5, 132, 48, 38.4);
    CCRect* pLevel9Rect = new CCRect(189, 132, 48, 38.4);
    CCRect* pLevel10Rect = new CCRect(247.5, 132, 48, 38.4);
    CCRect* pLevel11Rect = new CCRect(306, 132, 48, 38.4);
    CCRect* pLevel12Rect = new CCRect(364.5, 132, 48, 38.4);
    CCRect* pLevel13Rect = new CCRect(72, 77, 48, 38.4);
    CCRect* pLevel14Rect = new CCRect(130.5, 77, 48, 38.4);
    CCRect* pLevel15Rect = new CCRect(189, 77, 48, 38.4);
    CCRect* pLevel16Rect = new CCRect(247.5, 77, 48, 38.4);
    CCRect* pLevel17Rect = new CCRect(306, 77, 48, 38.4);
    CCRect* pLevel18Rect = new CCRect(364.5, 77, 48, 38.4);
    CCRect* pLevel19Rect = new CCRect(72, 21, 48, 38.4);
    CCRect* pLevel20Rect = new CCRect(130.5, 21, 48, 38.4);
    CCRect* pLevel21Rect = new CCRect(189, 21, 48, 38.4);
    CCRect* pLevel22Rect = new CCRect(247.5, 21, 48, 38.4);
    CCRect* pLevel23Rect = new CCRect(306, 21, 48, 38.4);
    CCRect* pLevel24Rect = new CCRect(364.5, 21, 48, 38.4);
    CCRect* pLeftDirectionRect = new CCRect(0, 112, 40, 16);
    CCRect* pRightDirectionRect = new CCRect(400, 112, 40, 16);
    
    if (pHomeTextureRect->containsPoint(location) or pGameTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CCLOG("Remove");
    } else if (pRightDirectionRect->containsPoint(location)) {
        if (mapType < 5) {
            CCMoveBy* moveRiBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            CCMoveBy* moveWestBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            CCMoveBy* moveTaleBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            CCMoveBy* moveCnBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            CCMoveBy* moveEvilBy = CCMoveBy::create(0.5f, ccp(-480, 0));
            //level_ri->setVisible(false);
            level_ri->runAction(moveRiBy);
            level_west->runAction(moveWestBy);
            level_tale->runAction(moveTaleBy);
            level_cn->runAction(moveCnBy);
            level_evil->runAction(moveEvilBy);
            
            mapType++;
        }
    } else if (pLeftDirectionRect->containsPoint(location)) {
        if (mapType > 1) {
            CCMoveBy* moveRiBy = CCMoveBy::create(0.5f, ccp(480, 0));
            CCMoveBy* moveWestBy = CCMoveBy::create(0.5f, ccp(480, 0));
            CCMoveBy* moveTaleBy = CCMoveBy::create(0.5f, ccp(480, 0));
            CCMoveBy* moveCnBy = CCMoveBy::create(0.5f, ccp(480, 0));
            CCMoveBy* moveEvilBy = CCMoveBy::create(0.5f, ccp(480, 0));
            //level_ri->setVisible(false);
            level_ri->runAction(moveRiBy);
            level_west->runAction(moveWestBy);
            level_tale->runAction(moveTaleBy);
            level_cn->runAction(moveCnBy);
            level_evil->runAction(moveEvilBy);
            
            mapType--;
        }
    } else if (pLevel1Rect->containsPoint(location)) {
        levelNum = 1;
        initNormalGame();
    } else if (pLevel2Rect->containsPoint(location)) {
        levelNum = 2;
        initNormalGame();
    } else if (pLevel3Rect->containsPoint(location)) {
        levelNum = 3;
        initNormalGame();
    } else if (pLevel4Rect->containsPoint(location)) {
        levelNum = 4;
        initNormalGame();
    } else if (pLevel5Rect->containsPoint(location)) {
        levelNum = 5;
        initNormalGame();
    } else if (pLevel6Rect->containsPoint(location)) {
        levelNum = 6;
        initMouseGame();
    } else if (pLevel7Rect->containsPoint(location)) {
        levelNum = 7;
        initNormalGame();
    } else if (pLevel8Rect->containsPoint(location)) {
        levelNum = 8;
        initNormalGame();
    } else if (pLevel9Rect->containsPoint(location)) {
        levelNum = 9;
        initNormalGame();
    } else if (pLevel10Rect->containsPoint(location)) {
        levelNum = 10;
        initNormalGame();
    } else if (pLevel11Rect->containsPoint(location)) {
        levelNum = 11;
        initNormalGame();
    } else if (pLevel12Rect->containsPoint(location)) {
        levelNum = 12;
        initNormalGame();
    } else if (pLevel13Rect->containsPoint(location)) {
        levelNum = 13;
        initNormalGame();
    } else if (pLevel14Rect->containsPoint(location)) {
        levelNum = 14;
        initNormalGame();
    } else if (pLevel15Rect->containsPoint(location)) {
        levelNum = 15;
        initNormalGame();
    } else if (pLevel16Rect->containsPoint(location)) {
        levelNum = 16;
        initNormalGame();
    } else if (pLevel17Rect->containsPoint(location)) {
        levelNum = 17;
        initNormalGame();
    } else if (pLevel18Rect->containsPoint(location)) {
        levelNum = 18;
        initMouseGame();
    } else if (pLevel19Rect->containsPoint(location)) {
        levelNum = 19;
        initNormalGame();
    } else if (pLevel20Rect->containsPoint(location)) {
        levelNum = 20;
        initNormalGame();
    } else if (pLevel21Rect->containsPoint(location)) {
        levelNum = 21;
        initNormalGame();
    } else if (pLevel22Rect->containsPoint(location)) {
        levelNum = 22;
        initNormalGame();
    } else if (pLevel23Rect->containsPoint(location)) {
        levelNum = 23;
        initNormalGame();
    } else if (pLevel24Rect->containsPoint(location)) {
        levelNum = 24;
        initNormalGame();
    } 
    return true;
}

void Process::initNormalGame()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
    CCScene* pGameScene = NormalGameScene::scene();
    CCDirector::sharedDirector()->replaceScene(pGameScene);
}

void Process::initMouseGame()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
    CCScene* pGameScene = MouseGameScene::scene();
    CCDirector::sharedDirector()->replaceScene(pGameScene);
}