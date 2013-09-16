//
//  Background.cpp
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#include "Background.h"

#include "cocos2d.h"
#include "BackgroundLoader.h"
#include "LevelLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Background::onEnter()
{
    CCLayer::onEnter();
    
    level = LevelLoader::load();
    levelLayer->addChild(level, 0, 201);
    
    this->setTouchEnabled(true);
    
    this->setXSpeed(0);
}

bool Background::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool Background::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLayer", CCLayer*, this->levelLayer);
    
    return false;
}

void Background::ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent)
{
    CCTouch* pTouch = (CCTouch*)(pTouches->anyObject());
    CCPoint location = pTouch->getLocation();
    CCPoint oldLocation = pTouch->getPreviousLocation();
    CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
    CCRect touchEnableRect = CCRectMake(0,150,winSize.width,winSize.height-150);
    if (touchEnableRect.containsPoint(location) and touchEnableRect.containsPoint(oldLocation)) {
    if ((location.x>oldLocation.x and this->getPositionX()+location.x-oldLocation.x<=0) or (location.x<oldLocation.x and this->getPositionX()+location.x-oldLocation.x>=-480)) {
        this->setPosition(ccp(this->getPositionX()+location.x-oldLocation.x, this->getPositionY()));
    }
    }
}

void Background::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
    CCFiniteTimeAction* pMoveTo;
    if (this->getPositionX()<-480) {
        pMoveTo = CCMoveTo::create(0.12f, ccp(-480, this->getPositionY()));
        this->runAction(pMoveTo);
    } else if (this->getPositionX()>0) {
        pMoveTo = CCMoveTo::create(0.12f, ccp(0, this->getPositionY()));
        this->runAction(pMoveTo);
    }
}

void Background::update(float delta)
{
    CCPoint oldPosition = this->getPosition();
    if ((oldPosition.x<0 and this->getXSpeed()>0) or (oldPosition.x>-480 and this->getXSpeed()<0)) {
        float xNew = oldPosition.x + xSpeed*delta;
        this->setPosition(ccp(xNew, oldPosition.y));
    }
}
