//
//  Load.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Load.h"

#include "cocos2d.h"
#include "LoadLoader.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"
#include "StoryScene.h"
#include "StaticData.h"
#include "JsonBox.h"

USING_NS_CC;
USING_NS_CC_EXT;

std::string Load::sharedSessionId = "";
struct CQPlayer Load::sharedPlayer = {};
CCNode* Load::sharedInstance = NULL;

CCScene* Load::scene()
{
    CCScene* scene = CCScene::create();
    sharedInstance = LoadLoader::load();
    
    scene->addChild(sharedInstance);
    
    return scene;
}

void Load::onEnter()
{
    CCLayer::onEnter();
    
    std::string uid = CCUserDefault::sharedUserDefault()->getStringForKey("openUDID");
    std::string token = CCUserDefault::sharedUserDefault()->getStringForKey("deviceToken");
    std::string ver = CCUserDefault::sharedUserDefault()->getStringForKey("appVersion");
    std::string server = STATIC_DATA_STRING("server");
    char url[255];
    sprintf(url, "%suser/loginApi&uid=%s&ver=%s&token=%s", server.c_str(), uid.c_str(), ver.c_str(), token.c_str());
    cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
    request->setUrl(url);
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(Load::onLoginRequestCompleted));
    request->setTag("login");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
    
    CCScene* pScene = MainMenuScene::scene();
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->replaceScene(pScene);
}



void Load::onLoginRequestCompleted(CCHttpClient *sender, CCHttpResponse *response)
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
    const std::string jsonStr(buffer->begin(),buffer->end());
    JsonBox::Value json;
    json.loadFromString(jsonStr);
    
    sharedSessionId = json["data"]["SID"].getString();
    
    char url[255];
    std::string server = STATIC_DATA_STRING("server");
    
    // create a scene. it's an autorelease object
    //CCScene* pScene;
    if (json["data"]["result"].getBoolean()) {
        sprintf(url, "%splayer/playerApi&SID=%s", server.c_str(), sharedSessionId.c_str());
        cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
        request->setUrl(url);
        request->setRequestType(CCHttpRequest::kHttpGet);
        request->setResponseCallback(this, httpresponse_selector(Load::onPlayerRequestCompleted));
        request->setTag("player");
        cocos2d::extension::CCHttpClient::getInstance()->send(request);
        request->release();

        //CCScene* pScene = MainMenuScene::scene();
        //CCDirector *pDirector = CCDirector::sharedDirector();
        //pDirector->replaceScene(pScene);
    } else {
        std::string term = CCUserDefault::sharedUserDefault()->getStringForKey("deviceType");
        std::string os = CCUserDefault::sharedUserDefault()->getStringForKey("osType");
        std::string uid = CCUserDefault::sharedUserDefault()->getStringForKey("openUDID");
        std::string ver = CCUserDefault::sharedUserDefault()->getStringForKey("appVersion");
        
        sprintf(url, "%suser/registerApi&name=%s&inviterCode=&term=%s&os=%s&ver=%s&SID=%s", server.c_str(), uid.substr(0,5).c_str(), term.c_str(), os.c_str(), ver.c_str(), sharedSessionId.c_str());
        
        cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
        request->setUrl(url);
        request->setRequestType(CCHttpRequest::kHttpGet);
        request->setResponseCallback(this, httpresponse_selector(Load::onRegisterRequestCompleted));
        request->setTag("register");
        cocos2d::extension::CCHttpClient::getInstance()->send(request);
        request->release();
    }
}

void Load::onRegisterRequestCompleted(CCHttpClient *sender, CCHttpResponse *response)
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
    const std::string jsonStr(buffer->begin(),buffer->end());
    JsonBox::Value json;
    json.loadFromString(jsonStr);
    
    
    char url[255];
    std::string server = STATIC_DATA_STRING("server");
    
    if (json["data"]["result"].getBoolean()) {
        sprintf(url, "%splayer/playerApi&SID=%s", server.c_str(), sharedSessionId.c_str());
        cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
        request->setUrl(url);
        request->setRequestType(CCHttpRequest::kHttpGet);
        request->setResponseCallback(this, httpresponse_selector(Load::onPlayerRequestCompleted));
        request->setTag("player");
        cocos2d::extension::CCHttpClient::getInstance()->send(request);
        request->release();
    }
}

void Load::onPlayerRequestCompleted(CCHttpClient *sender, CCHttpResponse *response)
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
    const std::string jsonStr(buffer->begin(),buffer->end());
    JsonBox::Value json;
    json.loadFromString(jsonStr);
    
    if (json["data"]["playerId"].getInt()) {
        sharedPlayer.playerId = json["data"]["playerId"].getInt();
        sharedPlayer.playerName = json["data"]["playerName"].getString();
        sharedPlayer.combats = json["data"]["combats"].getInt();
        sharedPlayer.stars = json["data"]["stars"].getInt();
        sharedPlayer.level = json["data"]["level"].getInt();
        
        CCScene* pScene = MainMenuScene::scene();
        CCDirector *pDirector = CCDirector::sharedDirector();
        pDirector->replaceScene(pScene);
    }

}
