//
//  GameOverScene.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__GameOverScene__
#define __miwu__GameOverScene__

#include "cocos2d.h"
#include "cocos-ext.h"

class GameOverScene : public cocos2d::CCLayer
{
public:
    static cocos2d::CCScene* scene();
    
    virtual bool init(); 
    
    void pressedPlay(cocos2d::CCObject * pSender);
    
    CREATE_FUNC(GameOverScene);
};

#endif /* defined(__miwu__GameOverScene__) */
