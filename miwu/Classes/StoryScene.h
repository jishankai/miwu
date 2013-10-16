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
    int storyCount;
    
    int i = 1;
    cocos2d::CCString* pString;
    
    cocos2d::CCSprite* story1;
    cocos2d::CCSprite* story2;
    cocos2d::CCSprite* story3;
    cocos2d::CCSprite* story4;
    
    static cocos2d::CCScene* scene();
    
    virtual bool init(); 

    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void type(cocos2d::CCNode* sender, cocos2d::CCLabelBMFont* label);
    
    CREATE_FUNC(StoryScene);
};

#endif /* defined(__miwu__StoryScene__) */
