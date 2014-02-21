//
//  Equip.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Equip.h"

#include "cocos2d.h"
#include "EquipLoader.h"

#include "StaticData.h"
#include "JsonBox.h"
#include "Load.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Equip::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);

    char url[255];
    std::string server = STATIC_DATA_STRING("server");
    sprintf(url, "%sweapons/infoApi&SID=%s", server.c_str(), Load::sharedSessionId.c_str());
    request->setUrl(url);
    request->setRequestType(CCHttpRequest::kHttpGet);
    request->setResponseCallback(this, httpresponse_selector(Equip::onInfoRequestCompleted));
    request->setTag("weapons");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
}

void Equip::onInfoRequestCompleted(CCHttpClient *sender, CCHttpResponse *response)
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
      this->clearEquip();
        JsonBox::Array weapons  = json["data"]["weapons"].getArray();
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

bool Equip::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(4, 280, 64, 32);
    CCRect* pGameTextureRect = new CCRect(410, 280, 64, 32);
    CCRect* pLeftTextureRect = new CCRect(0, 0, 64, 32);
    CCRect* pRightTextureRect = new CCRect(416, 0, 64, 32);
    
    if (pHomeTextureRect->containsPoint(location) or pGameTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CCLOG("Remove");
    } /*else {
        if (this->dialog->isVisible()) {
            this->dialog->setVisible(false);
        } else {
            this->dialog->setVisible(true);
        }
    }*/
    if (pLeftTextureRect->containsPoint(location) && equipCount<12) {
        equipCount++;
        equipList->setPositionX(-51.82*equipCount);
    }
    if (pRightTextureRect->containsPoint(location) && equipCount>0) {
        equipCount--;
        equipList->setPositionX(-51.82*equipCount);
    }
    return true;
}

bool Equip::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "equipList", CCNode*, this->equipList);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_circle", CCSprite*, this->ring_circle);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_agi", CCSprite*, this->ring_agi);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_exp", CCSprite*, this->ring_exp);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_hp", CCSprite*, this->ring_hp);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_mp", CCSprite*, this->ring_mp);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_plant", CCSprite*, this->ring_plant);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_pray", CCSprite*, this->ring_pray);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_reborn", CCSprite*, this->ring_reborn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_save", CCSprite*, this->ring_save);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring_treasure", CCSprite*, this->ring_treasure);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_cure", CCSprite*, this->scepter_cure);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_disaster", CCSprite*, this->scepter_disaster);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_fire", CCSprite*, this->scepter_fire);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_fish", CCSprite*, this->scepter_fish);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_flash", CCSprite*, this->scepter_flash);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_food", CCSprite*, this->scepter_food);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_gold", CCSprite*, this->scepter_gold);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_man", CCSprite*, this->scepter_man);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_poison", CCSprite*, this->scepter_poison);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_star", CCSprite*, this->scepter_star);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_wind", CCSprite*, this->scepter_wind);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scepter_woman", CCSprite*, this->scepter_woman);
    
    return false;
}

void Equip::clearEquipExceptRingCircle()
{
    this->ring_agi->setVisible(false);
    this->ring_exp->setVisible(false);
    this->ring_hp->setVisible(false);
    this->ring_mp->setVisible(false);
    this->ring_plant->setVisible(false);
    this->ring_pray->setVisible(false);
    this->ring_reborn->setVisible(false);
    this->ring_save->setVisible(false);
    this->ring_treasure->setVisible(false);
    this->scepter_cure->setVisible(false);
    this->scepter_disaster->setVisible(false);
    this->scepter_fire->setVisible(false);
    this->scepter_fish->setVisible(false);
    this->scepter_flash->setVisible(false);
    this->scepter_food->setVisible(false);
    this->scepter_gold->setVisible(false);
    this->scepter_man->setVisible(false);
    this->scepter_poison->setVisible(false);
    this->scepter_star->setVisible(false);
    this->scepter_wind->setVisible(false);
    this->scepter_woman->setVisible(false);
}

void Equip::clearEquip()
{
    this->clearEquipExceptRingCircle();
    this->ring_circle->setVisible(false);
}
