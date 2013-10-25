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

void Process::onEnter()
{
    this->url = "http://localhost/~jishankai/miwu/index.php?r=user/loginApi";
    this->requestApi();
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
}

bool Process::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(4, 280, 64, 32);
    CCRect* pGameTextureRect = new CCRect(410, 280, 64, 32);
    
    CCRect* pNormalGameTextureRect = new CCRect(78, 189, 80, 32);
    CCRect* pMouseGameTextureRect = new CCRect(194, 189, 80, 32);
    if (pHomeTextureRect->containsPoint(location) or pGameTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CCLOG("Remove");
    } else if (pNormalGameTextureRect->containsPoint(location)) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
        CCScene* pGameScene = NormalGameScene::scene();
        CCDirector::sharedDirector()->replaceScene(pGameScene);
    } else if (pMouseGameTextureRect->containsPoint(location)) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
        CCScene* pGameScene = MouseGameScene::scene();
        CCDirector::sharedDirector()->replaceScene(pGameScene);
    }
    return true;
}