//
//  GameSceneLoader.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__GameSceneLoader__
#define __miwu__GameSceneLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "GameScene.h"

class GameSceneLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameSceneLoader, loader);
    static GameScene* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameScene);
    
};

#endif /* defined(__miwu__GameSceneLoader__) */
