//
//  ApiParser.cpp
//  miwu
//
//  Created by Ji Shankai on 13-10-20.
//
//

#include "ApiParser.h"

USING_NS_CC;
USING_NS_CC_EXT;

void ApiParser::requestApi(const char* url)
{
    cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
    request->setUrl(url);
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(ApiParser::onHttpRequestCompleted));
    request->setTag("Process");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
}