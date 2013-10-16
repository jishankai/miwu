//
//  Soldier.h
//  miwu
//
//  Created by Ji Shankai on 13-8-14.
//
//

#ifndef __miwu__Soldier__
#define __miwu__Soldier__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "GameObject.h"

class Soldier : public GameObject
{  
public:
    bool isS9;
    bool isS6;
    const char* effectSoundFileName;
    virtual bool init();
    virtual void onEnter();
    virtual void update(float delta, float width);
    virtual void update(float delta);
    virtual void handleCollisionWith(GameObject* gameObject);
    virtual void resetSpeed();
    virtual bool isMaxHp();
};

#endif /* defined(__miwu__Soldier__) */
