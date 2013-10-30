//
//  miwuAppDelegate.cpp
//  miwu
//
//  Created by Ji Shankai on 13-7-16.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"
#include "StoryScene.h"
#include "StaticData.h"

USING_NS_CC;
using namespace CocosDenshion;

typedef struct tagResource
{
    CCSize sizeInPixel;
    CCSize sizeDesign;
    char directory[100];
} Resource;

static Resource resPhone  =  { CCSizeMake(960, 640), CCSizeMake(480, 320), "resources-iphone" };
static Resource resPhoneRetina =  { CCSizeMake(960, 640), CCSizeMake(960, 640), "resources-iphonehd"   };
static Resource resPhone5Retina =  { CCSizeMake(960, 640), CCSizeMake(1136, 640), "resources-iphonehd"   };
static Resource resTable =  { CCSizeMake(1024, 768), CCSizeMake(512, 384), "resources-ipad"   };
static Resource resTableRetina  =  { CCSizeMake(2048, 1536), CCSizeMake(512, 384), "resources-ipadhd" };

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize notification
    
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    
    //设置素材目录
    CCSize frameSize = pEGLView->getFrameSize();
    Resource actualResource;
    float actualHeight = fmin(frameSize.width, frameSize.height);
    float actualWidth = fmax(frameSize.width, frameSize.height);
    
    if (actualHeight > resTable.sizeInPixel.height)
    {
        actualResource = resTableRetina;
    }
    else if (actualHeight > resPhoneRetina.sizeInPixel.height)
    {
        actualResource = resTable;
    }
    else if (actualHeight > resPhone.sizeInPixel.height)
    {
        actualResource = resPhoneRetina;
        if (actualWidth > resPhoneRetina.sizeInPixel.width)
        {
            actualResource = resPhone5Retina;
        }
    }
    else
    {
        actualResource = resPhone;
    }
    
    //std::vector<std::string> resDirOrders;
    //resDirOrders.push_back(actualResource.directory);
    //CCFileUtils::sharedFileUtils()->setSearchPaths(resDirOrders);
    pDirector->setContentScaleFactor(1.0 *actualResource.sizeInPixel.width / actualResource.sizeDesign.width);
    
    // Set the design resolution
    pEGLView->setDesignResolutionSize(actualResource.sizeDesign.width, actualResource.sizeDesign.height, kResolutionNoBorder);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("storyboard.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("battle_ui.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ri.plist");
    
    std::string uid = CCUserDefault::sharedUserDefault()->getStringForKey("openUDID");
    std::string token = CCUserDefault::sharedUserDefault()->getStringForKey("deviceToken");
    std::string ver = CCUserDefault::sharedUserDefault()->getStringForKey("appVersion");
    std::string server = STATIC_DATA_STRING("server");
    char url[255];
    sprintf(url, "%suser/loginApi&uid=%s&ver=%s&token=%s", server.c_str(), uid.c_str(), ver.c_str(), token.c_str());
    this->requestApi(url);
    std::string sid = this->json["data"]["SID"].getString();
    CCUserDefault::sharedUserDefault()->setStringForKey("sessionId", sid);

    // create a scene. it's an autorelease object
    CCScene* pScene;
    if (this->json["data"]["result"].getBoolean()) {
        pScene = MainMenuScene::scene();
    } else {
        std::string term = CCUserDefault::sharedUserDefault()->getStringForKey("deviceType");
        std::string os = CCUserDefault::sharedUserDefault()->getStringForKey("osType");
        sprintf(url, "%suser/regiserApi&name=%s&inviterCode=&term=%s&os=%s&SID=%s", server.c_str(), uid.c_str(), term.c_str(), os.c_str(), this->json["data"]["SID"].getString().c_str());
        this->requestApi(url);
        if (this->json["data"]["result"].getBoolean()) {
            pScene = StoryScene::scene();
        } else {
            CCLOG("Register Failed!");
        }
    }
    
    sprintf(url, "%splayer/playerApi&SID=%s", server.c_str(), sid.c_str());
    CCUserDefault::sharedUserDefault()->setIntegerForKey("combats", this->json["data"]["combats"].getInt());
    CCUserDefault::sharedUserDefault()->setIntegerForKey("level", this->json["data"]["level"].getInt());
    CCUserDefault::sharedUserDefault()->setIntegerForKey("stars", this->json["data"]["stars"].getInt());
    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
