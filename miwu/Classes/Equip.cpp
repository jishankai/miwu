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

USING_NS_CC;
USING_NS_CC_EXT;

void Equip::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
    this->clearEquip();
    this->scepter_fish->setVisible(true);
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