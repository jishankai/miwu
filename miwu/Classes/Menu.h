//
//  Menu.h
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#ifndef __CocosDragon_x__Menu__
#define __CocosDragon_x__Menu__

#include "cocos2d.h"
#include "cocos-ext.h"

class Menu : public cocos2d::CCLayer, public cocos2d::extension::CCBSelectorResolver, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    cocos2d::CCLayer* levelLayer;
    cocos2d::CCLayer* backgroundLayer;
    cocos2d::CCNode* level;
    cocos2d::CCSprite* yellowRect;
    cocos2d::CCSprite* blueRect;
    cocos2d::CCLabelTTF* foodValue;
    cocos2d::CCLabelTTF* manaValue;
    
    float food;
    float mana;
    
public:
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Menu, create);
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    void pressedLeft(cocos2d::CCObject * pSender);
    void pressedRight(cocos2d::CCObject * pSender);
    void pressedRat(cocos2d::CCObject * pSender);
    void pressedRabit(cocos2d::CCObject * pSender);
    void pressedRhinoceros(cocos2d::CCObject * pSender);
    void pressedPenguin(cocos2d::CCObject * pSender);
    void pressedMonkey(cocos2d::CCObject * pSender);
    void pressedDinosaur(cocos2d::CCObject * pSender);
    void pressedBear(cocos2d::CCObject * pSender);
    void pressedKangaroo(cocos2d::CCObject * pSender);
    void pressedTortoise(cocos2d::CCObject * pSender);
    
    void update(float delta);
};

#endif /* defined(__CocosDragon_x__Menu__) */
