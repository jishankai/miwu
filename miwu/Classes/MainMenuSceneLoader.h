//
//  MainMenuSceneLoader.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef miwu_MainMenuSceneLoader_h
#define miwu_MainMenuSceneLoader_h

#include "cocos2d.h"
#include "cocos-ext.h"

#include "MainMenuScene.h"

class MainMenuSceneLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainMenuSceneLoader, loader);
    static MainMenuScene* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainMenuScene);

};


#endif
