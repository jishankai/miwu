//
//  Menu.cpp
//  CocosDragon-x
//
//  Created by long on 2013-03-01.
//
//

#include "Menu.h"

#include "MenuLoader.h"
#include "GameSceneLoader.h"

#include "Background.h"

#include "BearLoader.h"
#include "RatLoader.h"
#include "RabitLoader.h"
#include "RhinocerosLoader.h"
#include "PenguinLoader.h"
#include "MonkeyLoader.h"
#include "DinosaurLoader.h"
#include "KangarooLoader.h"
#include "TortoiseLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

void Menu::onEnter()
{
    CCLayer::onEnter();
    GameScene* gameScene = GameScene::sharedScene();
    backgroundLayer = gameScene->backgroundLayer;
    levelLayer = ((Background*)backgroundLayer->getChildByTag(101))->levelLayer;
    level = levelLayer->getChildByTag(201);
    
    food = 0;
    mana = 0;
    // Schedule a selector that is called every frame
    this->scheduleUpdate();

}

SEL_MenuHandler Menu::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedLeft:", Menu::pressedLeft);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedRight:", Menu::pressedRight);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedRat:", Menu::pressedRat);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedRabit:", Menu::pressedRabit);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedTortoise:", Menu::pressedTortoise);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedRhinoceros:", Menu::pressedRhinoceros);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedPenguin:", Menu::pressedPenguin);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedMonkey:", Menu::pressedMonkey);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedKangaroo:", Menu::pressedKangaroo);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedDinosaur:", Menu::pressedDinosaur);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedBear:", Menu::pressedBear);
    return NULL;
}

SEL_CCControlHandler Menu::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
    return NULL;
}

bool Menu::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool Menu::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "yellowRect", CCSprite*, this->yellowRect);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "blueRect", CCSprite*, this->blueRect);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "foodValue", CCLabelTTF*, this->foodValue);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "manaValue", CCLabelTTF*, this->manaValue);
    return false;
}

void Menu::pressedLeft(cocos2d::CCObject *pSender)
{
    backgroundLayer->setPositionX(backgroundLayer->getPositionX()+20);
}

void Menu::pressedRight(cocos2d::CCObject *pSender)
{
    backgroundLayer->setPositionX(backgroundLayer->getPositionX()-20);
}

void Menu::pressedRat(cocos2d::CCObject *pSender)
{
    CCNode* rat = RatLoader::load();
    rat->setPosition(ccp(100, 160));
    level->addChild(rat);
}

void Menu::pressedRhinoceros(cocos2d::CCObject *pSender)
{
    CCNode* rhinoceros = RhinocerosLoader::load();
    rhinoceros->setPosition(ccp(100, 160));
    level->addChild(rhinoceros);
}

void Menu::pressedRabit(cocos2d::CCObject *pSender)
{
    CCNode* rabit = RabitLoader::load();
    rabit->setPosition(ccp(100, 160));
    level->addChild(rabit);
}

void Menu::pressedPenguin(cocos2d::CCObject *pSender)
{
    CCNode* penguin = PenguinLoader::load();
    penguin->setPosition(ccp(100, 160));
    level->addChild(penguin);
}

void Menu::pressedTortoise(cocos2d::CCObject *pSender)
{
    CCNode* tortoise = TortoiseLoader::load();
    tortoise->setPosition(ccp(100, 160));
    tortoise->addChild(tortoise);
}

void Menu::pressedMonkey(cocos2d::CCObject *pSender)
{
    CCNode* monkey = MonkeyLoader::load();
    monkey->setPosition(ccp(100, 160));
    level->addChild(monkey);
}

void Menu::pressedBear(cocos2d::CCObject *pSender)
{
    CCNode* bear = BearLoader::load();
    bear->setPosition(ccp(100, 160));
    level->addChild(bear);
}

void Menu::pressedKangaroo(cocos2d::CCObject *pSender)
{
    CCNode* kangaroo = KangarooLoader::load();
    kangaroo->setPosition(ccp(100, 160));
    level->addChild(kangaroo);
}

void Menu::pressedDinosaur(cocos2d::CCObject *pSender)
{
    CCNode* dinosaur = DinosaurLoader::load();
    dinosaur->setPosition(ccp(100, 160));
    level->addChild(dinosaur);
}

void Menu::update(float delta)
{
    food += delta;
    mana += delta;
    
    CCString* newFood = CCString::createWithFormat("%f", food);
    foodValue->setString(newFood->getCString());
    
    CCString* newMana = CCString::createWithFormat("%f", mana);
    manaValue->setString(newMana->getCString());
}