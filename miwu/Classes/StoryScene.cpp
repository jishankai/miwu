//
//  StoryScene.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "StoryScene.h"

#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "StaticData.h"

USING_NS_CC;
USING_NS_CC_EXT;

CCScene* StoryScene::scene()
{
    CCScene* scene = CCScene::create();
    
    StoryScene* layer = StoryScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool StoryScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
    
    //CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    //CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    storyCount = 1;
    story1 = CCSprite::createWithSpriteFrameName("1.png");
    story1->setAnchorPoint(CCPointZero);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("main.mp3", true);
    this->addChild(story1);

    std::string type("story_0");
    firstLineLabel = PrintingLabel::create(type, "Arial", 1.0f);
    this->addChild(firstLineLabel, 100);
    firstLineLabel->setPosition(ccp(50, 30));
    return true;
}

void StoryScene::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
    switch (storyCount) {
        case 1:
        {
            onTounchHandler("2.png", story1, story2, "story_1", "story_2");
            break;
        }
        case 2:
        {
            onTounchHandler("3.png", story2, story3, "story_3", NULL);
            break;
        }
        case 3:
        {
            onTounchHandler("4.png", story3, story4, "story_4", "story_5");
            break;
        }
        case 4:
        {
            if (firstLineLabel->getComplete() == false)
            {
                firstLineLabel->displayComplete();
                if (secondLineLabel && secondLineLabel->getComplete() == false)
                {
                    secondLineLabel->displayComplete();
                }
                else if (secondLineLabel && secondLineLabel->getComplete() == true)
                {
                    endStory();
                }
            }
            else
            {
                if (secondLineLabel && secondLineLabel->getComplete() == false)
                {
                    secondLineLabel->displayComplete();
                }
                else
                {
                    endStory();
                }
            }
            break;
        }
        default:
            break;
    }
}

void StoryScene::onTounchHandler(const char *storyName, CCSprite *prevStory, CCSprite *curStory, const char *firstLine, const char *secondLine)
{
    if (firstLineLabel->getComplete() == false){
        firstLineLabel->displayComplete();
        if (secondLineLabel && secondLineLabel->getComplete() == false)
        {
            secondLineLabel->displayComplete();
        }
        else if (secondLineLabel && secondLineLabel->getComplete() == true)
        {
            changeStory(storyName, prevStory, curStory, firstLine, secondLine);
        }
    }
    else{
        if (secondLineLabel && secondLineLabel->getComplete() == false)
        {
            secondLineLabel->displayComplete();
        }
        else
        {
            changeStory(storyName, prevStory, curStory, firstLine, secondLine);
        }
    }
}

void StoryScene::changeStory(const char* storyName, CCSprite* prevStory, CCSprite* curStory,
                             const char* firstLine, const char* secondLine)
{
    CCSprite* story = CCSprite::createWithSpriteFrameName(storyName);
    story->setAnchorPoint(CCPointZero);
    this->removeChild(prevStory);
    this->addChild(story);
    story2 = curStory;
    
    this->removeChild(firstLineLabel);
    std::string firstLineType(firstLine);
    firstLineLabel = PrintingLabel::create(firstLineType, "Arial", 1.0f);
    this->addChild(firstLineLabel, 100);
    firstLineLabel->setPosition(ccp(30, 35));
    
    if (secondLine != NULL)
    {
        std::string secondLineType(secondLine);
        secondLineLabel = PrintingLabel::create(secondLineType, "Arial", 1.0f);
        this->addChild(secondLineLabel, 200);
        secondLineLabel->setPosition(ccp(100, 16));
    }
    else
    {
        this->removeChild(secondLineLabel);
        secondLineLabel = NULL;
    }
    
    if(storyCount <= 3) {
        storyCount++;
    }
}

void StoryScene::endStory()
{
    this->removeChild(story4);
    //CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
    CCScene* pMainMenuScene = MainMenuScene::scene();
    CCDirector::sharedDirector()->replaceScene(pMainMenuScene);
}