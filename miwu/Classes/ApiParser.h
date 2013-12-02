//
//  ApiParser.h
//  miwu
//
//  Created by Ji Shankai on 13-10-20.
//
//

#ifndef __miwu__ApiParser__
#define __miwu__ApiParser__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "JsonBox.h"

class ApiParser : public cocos2d::CCLayer
{
public:
    JsonBox::Value json;
    virtual void requestApi(const char* url);
    virtual void onHttpRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
    
};

#endif /* defined(__miwu__ApiParser__) */
