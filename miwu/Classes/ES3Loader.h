//
//  ES3Loader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-1.
//
//

#ifndef __miwu__ES3Loader__
#define __miwu__ES3Loader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "ES3.h"

class ES3Loader : public cocos2d::extension::CCNodeLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ES3Loader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ES3);
    
};


#endif /* defined(__miwu__ES3Loader__) */
