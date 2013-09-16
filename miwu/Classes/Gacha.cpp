//
//  Gacha.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Gacha.h"

#include "cocos2d.h"
#include "GachaLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Gacha::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
}

bool Gacha::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    //CCRect* pHomeTextureRect = new CCRect(4, 280, 64, 32);
    //CCRect* pGameTextureRect = new CCRect(410, 280, 64, 32);
    
    if (this->dialog->isVisible()) {
        this->removeFromParentAndCleanup(true);
        CCLOG("Remove");
    } else {
        this->dialog->setVisible(true);
    }
    
    return true;
}
