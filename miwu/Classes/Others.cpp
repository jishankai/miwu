//
//  Others.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Others.h"

#include "cocos2d.h"
#include "OthersLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Others::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
}

bool Others::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(208, 215, 64, 32);
    //CCRect* pGameTextureRect = new CCRect(410, 280, 64, 32);
    
    if (!pHomeTextureRect->containsPoint(location)) { //or pGameTextureRect->containsPoint(location)) {
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
