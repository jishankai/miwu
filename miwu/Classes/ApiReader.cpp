//
//  ApiReader.cpp
//  miwu
//
//  Created by Ji Shankai on 13-7-6.
//
//

#include "ApiReader.h"

USING_NS_CC;
USING_NS_CC_EXT;

// on "init" you need to initialize your instance
bool ApiReader::init()
{
    return true;
}

bool ApiReader::read(const char* url)
{
    /*
    CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
    request->setUrl(url);
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, callfuncND_selector((ApiReader::onHttpRequestCompleted));
    request->setTag("api");//tag
    CCHttpClient::getInstance()->send(request);
    request->release();
     */
}

void ApiReader::onHttpRequestCompleted(CCHttpClient* client, CCHttpResponse* response)
{
    /*
    if (response->isSucceed()) {
        std::vector<char> *buffer = response->getResponseData();
        
    }
     */
}
