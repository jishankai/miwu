//
//  UpdateLayer.cpp
//  miwu
//
//  Created by Ji Shankai on 13-7-6.
//
//

#include "UpdateLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;


UpdateLayer::UpdateLayer()
{
    init();
}

UpdateLayer::~UpdateLayer()
{
    AssetsManager *pAssetsManager = getAssetsManager();
    CC_SAFE_DELETE(pAssetsManager);
}

bool UpdateLayer::init()
{
    CCLayer::init();
    
    createDownloadedDir();
    
    pProgressLabel = CCLabelTTF::create("", "Arial", 20);
    pProgressLabel->setPosition(ccp(100, 50));
    addChild(pProgressLabel);
    
    return true;
}

AssetsManager* UpdateLayer::getAssetsManager()
{
    static AssetsManager *pAssetsManager = NULL;
    
    if (! pAssetsManager)
    {
        pAssetsManager = new AssetsManager("https://raw.github.com/minggo/AssetsManagerTest/master/package.zip",
                                           "https://raw.github.com/minggo/AssetsManagerTest/master/version",
                                           pathToSave.c_str());
        pAssetsManager->setDelegate(this);
        pAssetsManager->setConnectionTimeout(3);
    }
    
    return pAssetsManager;
}

void UpdateLayer::createDownloadedDir()
{
    pathToSave = CCFileUtils::sharedFileUtils()->getWritablePath();
    pathToSave += "tmpdir";
    
    // Create the folder if it doesn't exist
}

void UpdateLayer::onError(AssetsManager::ErrorCode errorCode)
{
    if (errorCode == AssetsManager::kNoNewVersion)
    {
        pProgressLabel->setString("no new version");
    }
    
    if (errorCode == AssetsManager::kNetwork)
    {
        pProgressLabel->setString("network error");
    }
}

void UpdateLayer::onProgress(int percent)
{
    char progress[20];
    snprintf(progress, 20, "downloading %d%%", percent);
    pProgressLabel->setString(progress);
}

void UpdateLayer::onSuccess()
{
    pProgressLabel->setString("download ok");
}
