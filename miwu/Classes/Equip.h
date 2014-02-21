//
//  Equip.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__Equip__
#define __miwu__Equip__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "LayerWithDialog.h"

class Equip : public LayerWithDialog
{
private:
    cocos2d::CCNode* equipList;
    cocos2d::CCSprite* ring_circle;
    cocos2d::CCSprite* ring_agi;
    cocos2d::CCSprite* ring_exp;
    cocos2d::CCSprite* ring_hp;
    cocos2d::CCSprite* ring_mp;
    cocos2d::CCSprite* ring_plant;
    cocos2d::CCSprite* ring_pray;
    cocos2d::CCSprite* ring_reborn;
    cocos2d::CCSprite* ring_save;
    cocos2d::CCSprite* ring_treasure;
    cocos2d::CCSprite* scepter_cure;
    cocos2d::CCSprite* scepter_disaster;
    cocos2d::CCSprite* scepter_fire;
    cocos2d::CCSprite* scepter_fish;
    cocos2d::CCSprite* scepter_flash;
    cocos2d::CCSprite* scepter_food;
    cocos2d::CCSprite* scepter_gold;
    cocos2d::CCSprite* scepter_man;
    cocos2d::CCSprite* scepter_poison;
    cocos2d::CCSprite* scepter_star;
    cocos2d::CCSprite* scepter_wind;
    cocos2d::CCSprite* scepter_woman;
    
    int equipCount = 0;
    
    void clearEquipExceptRingCircle();
    void clearEquip();
    
public:
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Equip, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void onInfoRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
};

#endif /* defined(__miwu__Equip__) */
