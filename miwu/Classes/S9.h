//
//  S9.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__S9__
#define __miwu__S9__

#include "Soldier.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#define kCJ_S9_BASE_HP 400
#define kCJ_S9_BASE_ATK 50
#define kCJ_S9_StartSpeed 48
#define kCJ_S9_ACTION_RANGE 1
#define kCJ_S9_ATK_DELAY 1

#define kCJ_S9_NORMAL_SKILL_RATE 100
#define kCJ_S9_HALO_SKILL_RATE 10

class S9 : public Soldier
{

private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S9, create);
    
    virtual float radius();
    virtual float getLv();
};

#endif /* defined(__miwu__S9__) */
