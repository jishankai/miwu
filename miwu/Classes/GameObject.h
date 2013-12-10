//
//  GameObject.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__GameObject__
#define __miwu__GameObject__

#include "cocos2d.h"

class GameObject : public cocos2d::CCNode
{
public:
    cocos2d::CCSprite* bloodBar;
    const char* effectSoundFileName;
//    CC_SYNTHESIZE(bool, isScheduledForRemove, IsScheduledForRemove);
    CC_SYNTHESIZE(float, atk, Atk);
    CC_SYNTHESIZE(float, atkDelay, AtkDelay);
//    CC_SYNTHESIZE(float, delayCount, DelayCount);
    CC_SYNTHESIZE(float, hp, Hp);
    CC_SYNTHESIZE(float, maxHp, MaxHp);
    CC_SYNTHESIZE(float, xSpeed, XSpeed);
    CC_SYNTHESIZE(float, defaultSpeed, DefaultSpeed);
    CC_SYNTHESIZE(bool, isCollision, IsCollision);
    CC_SYNTHESIZE(int, actionRange, ActionRange);
    CC_SYNTHESIZE(int, curActionCount, CurActionCount);
    void resetCurActionCount();
    bool checkIsCollision(GameObject* gameObject);
    bool stopAction();
    void stop();
    
    virtual void atkHandler(float atk, GameObject* gameObject);
    virtual void reboundHeartHandler(GameObject* gameObject);
    virtual void reboundedHeartedHandler();
    virtual bool hurtToOther(float atk);
    virtual void deadHandler() = 0;
    virtual void drawCollisionLine() = 0;
    virtual float radius() = 0;
    virtual void update(float delta) = 0;
    virtual void handleCollisionWith(GameObject* gameObject) = 0;
    virtual void resetSpeed() = 0;
    virtual bool isMaxHp() = 0;
};

#endif /* defined(__miwu__GameObject__) */
