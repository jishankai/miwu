//
//  S3.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__S3__
#define __miwu__S3__

#include "Soldier.h"

#include "cocos2d.h"
#include "cocos-ext.h"

#define kCJ_S3_BASE_HP 100
#define kCJ_S3_BASE_ATK 20
#define kCJ_S3_StartSpeed 90
#define kCJ_S3_ACTION_RANGE 1
#define kCJ_S3_ATK_DELAY 0.5
#define kCJ_S3_NORMAL_SKILL_RATE 100
#define kCJ_S3_HALO_SKILL_RATE 50

class S3 : public Soldier
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S3, create);
    
    virtual float radius();
    virtual float getLv();
};


#endif /* defined(__miwu__S3__) */
