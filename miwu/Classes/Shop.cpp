//
//  Shop.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Shop.h"

#include "cocos2d.h"
#include "ShopLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Shop::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
}

bool Shop::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    LayerWithDialog::onAssignCCBMemberVariable(pTarget, pMemberVariableName, pNode);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coin", CCSprite*, this->coin);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "treasure", CCSprite*, this->treasure);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring", CCSprite*, this->ring);
    
    return false;
}

bool Shop::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
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
