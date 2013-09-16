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

class S3 : public Soldier
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(S3, create);
    
    virtual float radius();
};


#endif /* defined(__miwu__S3__) */
