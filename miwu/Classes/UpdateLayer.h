//
//  UpdateLayer.h
//  miwu
//
//  Created by Ji Shankai on 13-7-6.
//
//

#ifndef __miwu__UpdateLayer__
#define __miwu__UpdateLayer__

#include "cocos2d.h"
#include "AssetsManager.h"

class UpdateLayer : public cocos2d::CCLayer, public cocos2d::extension::AssetsManagerDelegateProtocol
{
public:
    UpdateLayer();
    ~UpdateLayer();
    virtual bool init();
       
    virtual void onError(cocos2d::extension::AssetsManager::ErrorCode errorCode);
    virtual void onProgress(int percent);
    virtual void onSuccess();
    
private:
    cocos2d::extension::AssetsManager* getAssetsManager();
    void createDownloadedDir();
    
    cocos2d::CCLabelTTF *pProgressLabel;
    std::string pathToSave;
    bool isUpdateItemClicked;
};

#endif /* defined(__miwu__UpdateLayer__) */
