//
//  StoryScene.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__StoryScene__
#define __miwu__StoryScene__

#include "cocos2d.h"
#include "cocos-ext.h"

class StoryScene : public cocos2d::CCLayer
{
public:
    static cocos2d::CCScene* scene();
    
    virtual bool init(); 
    
    void pressedPlay(cocos2d::CCObject * pSender);
    
    CREATE_FUNC(StoryScene);
};

#endif /* defined(__miwu__StoryScene__) */
