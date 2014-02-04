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

USING_NS_CC;
USING_NS_CC_EXT;

void Army::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
    
    this->clearArmyShow();
    this->show_s1->setVisible(true);
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
