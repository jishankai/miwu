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

void ApiParser::onHttpRequestCompleted(CCHttpClient *sender, CCHttpResponse *response)
{
    if (!response)
    {
        return;
    }
    
    // You can get original request type from: response->request->reqType
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        CCLog("%s completed", response->getHttpRequest()->getTag());
    }
    
    int statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
    CCLog("response code: %d", statusCode);
    
    if (!response->isSucceed())
    {
        CCLog("response failed");
        CCLog("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    // dump data
    std::vector<char> *buffer = response->getResponseData();
    const std::string jsonStr(buffer->begin(),buffer->end());
    json.loadFromString(jsonStr);
}
