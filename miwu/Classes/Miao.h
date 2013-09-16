//
//  Miao.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__Miao__
#define __miwu__Miao__

#include "GameObject.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class Miao : public GameObject
{

private:
    cocos2d::CCSprite* miaoSprite;
    cocos2d::CCSprite* circleSprite;
    
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Miao, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual void update(float delta);
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual float radius();
    virtual void resetSpeed();
    virtual bool isMaxHp();
};

#endif /* defined(__miwu__Miao__) */
