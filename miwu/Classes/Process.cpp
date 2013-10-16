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
    LayerWithDialog::onEnter();
    /*
    cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
    request->setUrl("http://127.0.0.1/~jishankai/miwu/index.php?r=user/loginApi&uid=1&ver=1.0");
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(Process::onHttpRequestCompleted));
    request->setTag("Process");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
    */
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

void Process::onHttpRequestCompleted(CCHttpClient *sender, CCHttpResponse *response)
{
    if (!response)
    {
        return;
    }
    
    // You can get original request type from: response->request->reqType
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        CCLog("%s completed", response->getHttpRequest()->getTag());
    }
    
    int statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
    CCLog("response code: %d", statusCode);
    
    if (!response->isSucceed())
    {
        CCLog("response failed");
        CCLog("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    // dump data
    std::vector<char> *buffer = response->getResponseData();
    printf("Http Test, dump data: ");
    for (unsigned int i = 0; i < buffer->size(); i++)
    {
        printf("%c", (*buffer)[i]);
    }
    printf("\n");
}
