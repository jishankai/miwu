//
//  ES3.h
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#ifndef __miwu__ES3__
#define __miwu__ES3__

#include "Enemy.h"

#include "cocos2d.h"
#include "cocos-ext.h"

class ES3 : public Enemy
{
    
private:
    bool init();
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ES3, create);
    
    virtual float radius();
};

#endif /* defined(__miwu__ES3__) */
