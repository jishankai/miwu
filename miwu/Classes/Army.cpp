//
//  Army.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Army.h"

#include "cocos2d.h"
#include "ArmyLoader.h"

#include "StaticData.h"
#include "JsonBox.h"
#include "Load.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Army::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);

    char url[255];
    std::string server = STATIC_DATA_STRING("server");
    sprintf(url, "%sarms/infoApi&SID=%s", server.c_str(), Load::sharedSessionId.c_str());
    request->setUrl(url);
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(Army::onInfoRequestCompleted));
    request->setTag("arms");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
}

void Army::onInfoRequestCompleted(CCHttpClient *sender, CCHttpResponse *response)
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
    JsonBox::Value json;
    json.loadFromString(jsonStr);
    
    if (json["data"]["isSuccess"].getBoolean()) {
        this->clearArmyShow();
        JsonBox::Array arms = json["data"]["arms"].getArray();
        for (i = 0; i < 9; i++) {
          switch(atoi(arms[i]["armId"].getString().c_str())) {
          case 1:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s1->setVisible(true);
            }
            break;
          case 2:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s2->setVisible(true);
            }
            break;
          case 3:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s3->setVisible(true);
            }
            break;
          case 4:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s4->setVisible(true);
            }
            break;
          case 5:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s5->setVisible(true);
            }
            break;
          case 6:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s6->setVisible(true);
            }
            break;
          case 7:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s7->setVisible(true);
            }
            break;
          case 8:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s8->setVisible(true);
            }
            break;
          case 9:
            if(atoi(arms[i]["level"].getString().c_str())>0) {
              this->show_s9->setVisible(true);
            }
            break;
          }
        }
    }
}

bool Army::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(4, 280, 64, 32);
    CCRect* pGameTextureRect = new CCRect(410, 280, 64, 32);
    
    if (pHomeTextureRect->containsPoint(location) or pGameTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CCLOG("Remove");
    } else {
        if (this->dialog->isVisible()) {
            this->dialog->setVisible(false);
        } else {
            this->dialog->setVisible(true);
        }
    }
    return true;
}

bool Army::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s1", CCSprite*, this->s1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s2", CCSprite*, this->s2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s3", CCSprite*, this->s3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s4", CCSprite*, this->s4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s5", CCSprite*, this->s5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s6", CCSprite*, this->s6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s7", CCSprite*, this->s7);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s8", CCSprite*, this->s8);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s9", CCSprite*, this->s9);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s1", CCSprite*, this->show_s1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s2", CCSprite*, this->show_s2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s3", CCSprite*, this->show_s3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s4", CCSprite*, this->show_s4);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s5", CCSprite*, this->show_s5);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s6", CCSprite*, this->show_s6);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s7", CCSprite*, this->show_s7);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s8", CCSprite*, this->show_s8);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "show_s9", CCSprite*, this->show_s9);
    
    return false;
}

void Army::clearArmyShow()
{
    this->show_s1->setVisible(false);
    this->show_s2->setVisible(false);
    this->show_s3->setVisible(false);
    this->show_s4->setVisible(false);
    this->show_s5->setVisible(false);
    this->show_s6->setVisible(false);
    this->show_s7->setVisible(false);
    this->show_s8->setVisible(false);
    this->show_s9->setVisible(false);
}
