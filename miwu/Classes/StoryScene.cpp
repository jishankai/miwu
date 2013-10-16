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
    CCLabelTTF* pLabelBMFont = CCLabelTTF::create();
    pLabelBMFont->setPosition(ccp(20,20));
    pString = CCString::createWithFormat("很久很久以前，这是一片被邪恶控制的大陆");
    int stringLength = pString->length();
    CCDelayTime* sleep = CCDelayTime::create(0.5f);
    CCCallFuncND* type = CCCallFuncND::create(this, callfuncND_selector(StoryScene::type), pLabelBMFont);
    CCSequence *seq = CCSequence::create(sleep, type, NULL);
    CCRepeat* repeat = CCRepeat::create(seq, stringLength);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("main.mp3", true);
    this->addChild(story1);
    this->addChild(pLabelBMFont,100);
    //this->runAction(repeat);
    return true;
}

void StoryScene::type(cocos2d::CCNode *sender, CCLabelBMFont *label)
{
    CCString* sFormat = CCString::createWithFormat("%%ds", i);
    CCString* pLabelString = CCString::createWithFormat(sFormat->getCString(), pString->getCString());
    
    label->setString(pLabelString->getCString());
    i++;
}

void StoryScene::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
    switch (storyCount) {
        case 1:
        {
            CCSprite* story = CCSprite::createWithSpriteFrameName("2.png");
            story->setAnchorPoint(CCPointZero);
            this->removeChild(story1);
            this->addChild(story);
            story2 = story;
            break;
        }
        case 2:
        {
            CCSprite* story = CCSprite::createWithSpriteFrameName("3.png");
            story->setAnchorPoint(CCPointZero);
            this->removeChild(story2);
            this->addChild(story);
            story3 = story;
            break;
        }
        case 3:
        {
            CCSprite* story = CCSprite::createWithSpriteFrameName("4.png");
            story->setAnchorPoint(CCPointZero);
            this->removeChild(story3);
            this->addChild(story);
            story4 = story;
            break;
        }
        case 4:
        {
            this->removeChild(story4);
            //CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
            CCScene* pMainMenuScene = MainMenuScene::scene();
            CCDirector::sharedDirector()->replaceScene(pMainMenuScene);
            break;
        }
        default:
            break;
    }
    if(storyCount<=3) {
        storyCount++;
    }
}