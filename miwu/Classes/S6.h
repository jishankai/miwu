//
//  S6.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__S6__
#define __miwu__S6__

#include "Soldier.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#define kCJ_S6_BASE_HP 180
#define kCJ_S6_BASE_ATK 20
#define kCJ_S6_StartSpeed 60
#define kCJ_S6_DEF 100

class S6 : public Soldier
{

private:    
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S6, create);
    
    virtual float radius();
    virtual float getLv();
};

#endif /* defined(__miwu__S6__) */
