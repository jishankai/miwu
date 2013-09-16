//
//  Medal.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Medal.h"

#include "cocos2d.h"
#include "MedalLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Medal::onEnter()
{
    LayerWithDialog::onEnter();
    
    this->setTouchEnabled(true);
}

bool Medal::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    CCPoint location = pTouch->getLocation();
    
    CCRect* pHomeTextureRect = new CCRect(4, 280, 64, 32);
    CCRect* pGameTextureRect = new CCRect(410, 280, 64, 32);
    
    if (pHomeTextureRect->containsPoint(location) or pGameTextureRect->containsPoint(location)) {
        this->removeFromParentAndCleanup(true);
        CCLOG("Remove");
    } 
    return true;
}
