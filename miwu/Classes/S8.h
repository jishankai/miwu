//
//  S8.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__S8__
#define __miwu__S8__

#include "Soldier.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#define kCJ_S8_BASE_HP 120
#define kCJ_S8_BASE_ATK 20
#define kCJ_S8_StartSpeed 42
#define kCJ_S8_DEF 100

class S8 : public Soldier
{

private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S8, create);
    
    virtual float radius();
    virtual float getLv();
};

#endif /* defined(__miwu__S8__) */
