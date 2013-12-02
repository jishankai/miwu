//
//  miwuAppDelegate.cpp
//  miwu
//
//  Created by Ji Shankai on 13-7-16.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "Load.h"

USING_NS_CC;
USING_NS_CC_EXT;
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
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui.plist");
   
    CCScene*  pScene = Load::scene();
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

