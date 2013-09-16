//
//  Level.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__Level__
#define __miwu__Level__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Miao.h"
#include "RBoss.h"

class Level : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    
public:
    Miao* miao;
    RBoss* boss;
    float randTime = 0;
    cocos2d::CCArray *_soldiers;
	cocos2d::CCArray *_enimies;

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Level, create);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);

    
    //virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    //virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

    
    void update(float delta);
};

#endif /* defined(__miwu__Level__) */
