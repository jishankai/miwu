//
//  MainMenuScene.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__MainMenuScene__
#define __miwu__MainMenuScene__

#include "cocos2d.h"
#include "cocos-ext.h"

class MainMenuScene : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    /*
    cocos2d::CCSprite* army;
    cocos2d::CCSprite* coin;
    cocos2d::CCSprite* equip;
    cocos2d::CCSprite* event;
    cocos2d::CCSprite* level;
    cocos2d::CCSprite* medal;
    cocos2d::CCSprite* miao;
    cocos2d::CCSprite* others;
    cocos2d::CCSprite* reward;
    cocos2d::CCSprite* ring;
    cocos2d::CCSprite* share;
    cocos2d::CCSprite* shop;
    cocos2d::CCSprite* treasure;
     */
    
public:
    static cocos2d::CCScene* scene();
    
    static MainMenuScene* sharedInstance;
    
    static MainMenuScene* sharedScene();
    
    virtual bool init();
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MainMenuScene, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    void pressedPlay(cocos2d::CCObject * pSender);
    
    void pressedPlayMouseGame(cocos2d::CCObject * pSender);
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    //virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

    
    //CREATE_FUNC(MainMenuScene);
};

#endif /* defined(__miwu__MainMenuScene__) */
