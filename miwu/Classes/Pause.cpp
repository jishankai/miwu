//
//  Pause.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Pause.h"

#include "cocos2d.h"
#include "PauseLoader.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "NormalGameScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Pause::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
}

bool Pause::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    LayerWithDialog::onAssignCCBMemberVariable(pTarget, pMemberVariableName, pNode);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "win", CCSprite*, this->win);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "lose", CCSprite*, this->lose);
    
    return false;
}


bool Pause::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(63, 25, 76.8, 32);
    CCRect* pGameTextureRect = new CCRect(200, 25, 76.8, 32);
    CCRect* pRestartTextureRect = new CCRect(339, 25, 76.8, 32);
    
    if (pHomeTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("main.mp3", true);
        CCScene* pMainMenuScene = MainMenuScene::scene();
        CCDirector::sharedDirector()->replaceScene(pMainMenuScene);
        CCDirector::sharedDirector()->resume();
        CCLOG("Remove");
    } else if (pGameTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CCDirector::sharedDirector()->resume();
        CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
        CCLOG("Resume");
    } else if (pRestartTextureRect->containsPoint(location)) {
//        this->dialog->setVisible(true);
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
        CCScene* pGameScene = NormalGameScene::scene();
        CCDirector::sharedDirector()->replaceScene(pGameScene);
        CCDirector::sharedDirector()->resume();
        CCLOG("Restart");
    } else if (this->dialog->isVisible()) {
        this->dialog->setVisible(false);
    }
    return true;
}
