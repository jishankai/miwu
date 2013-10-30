//
//  S7.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__S7__
#define __miwu__S7__

#include "Soldier.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#define kCJ_S7_BASE_HP 150
#define kCJ_S7_BASE_ATK 60
#define kCJ_S7_StartSpeed 42
#define kCJ_S7_DEF 100

class S7 : public Soldier
{

private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S7, create);
    
    virtual float radius();
    virtual float getLv();
};

#endif /* defined(__miwu__S7__) */
