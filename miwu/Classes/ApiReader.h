//
//  ApiReader.h
//  miwu
//
//  Created by Ji Shankai on 13-7-6.
//
//

#ifndef __miwu__ApiReader__
#define __miwu__ApiReader__

#include "cocos2d.h"
#include "cocos-ext.h"

class ApiReader
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    bool read(const char* url);
    
    // a selector callback
    void onHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response);
};


#endif /* defined(__miwu__ApiReader__) */
