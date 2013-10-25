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
#include "PrintingLabel.h"

class StoryScene : public cocos2d::CCLayer
{
public:
    int storyCount;
    
    int i = 0;
    cocos2d::CCString* storyString;
    
    cocos2d::CCSprite* story1;
    cocos2d::CCSprite* story2;
    cocos2d::CCSprite* story3;
    cocos2d::CCSprite* story4;
    
    PrintingLabel* firstLineLabel;
    PrintingLabel* secondLineLabel;
    
    static cocos2d::CCScene* scene();
    
    virtual bool init(); 

    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    CREATE_FUNC(StoryScene);
private:
    
    void onTounchHandler(const char *storyName, cocos2d::CCSprite *prevStory, cocos2d::CCSprite *curStory, const char *firstLine, const char *secondLine);
    
    void changeStory(const char* storyName, cocos2d::CCSprite* prevStory, cocos2d::CCSprite* curStory, const char* firstLine, const char* secondLine);
    
    void endStory();
};

#endif /* defined(__miwu__StoryScene__) */
