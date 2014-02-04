//
//  Menu.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__Menu__
#define __miwu__Menu__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Level.h"

class Menu : public cocos2d::CCLayer, public cocos2d::extension::CCBSelectorResolver, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    cocos2d::CCLayer* levelLayer;
    cocos2d::CCLayer* backgroundLayer;
    Level* level;
    cocos2d::CCSprite* redRect;
    cocos2d::CCSprite* blueRect;
    cocos2d::CCLabelTTF* foodValue;
    cocos2d::CCLabelTTF* manaValue;
    cocos2d::CCProgressTimer* redProcessBar;
    cocos2d::CCProgressTimer* blueProcessBar;
    cocos2d::CCSprite* leftArrow;
    cocos2d::CCSprite* rightArrow;
    cocos2d::CCSprite* pauseSprite;
    
    float food;
    float mana;
    
    bool init();
    
public:
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Menu, create);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    //void pressedLeft(cocos2d::CCObject * pSender);
    //void pressedRight(cocos2d::CCObject * pSender);
    void pressedPause(cocos2d::CCObject * pSender);
    void pressedS1(cocos2d::CCObject * pSender);
    void pressedS2(cocos2d::CCObject * pSender);
    void pressedS3(cocos2d::CCObject * pSender);
    void pressedS4(cocos2d::CCObject * pSender);
    void pressedS5(cocos2d::CCObject * pSender);
    void pressedS6(cocos2d::CCObject * pSender);
    void pressedS7(cocos2d::CCObject * pSender);
    void pressedS8(cocos2d::CCObject * pSender);
    void pressedS9(cocos2d::CCObject * pSender);
    
    void update(float delta);
    void spriteMoveFinished(cocos2d::CCNode* sender);
    
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void winHandler();
    
    void onBattleWinRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
};

#endif /* defined(__miwu__Menu__) */
