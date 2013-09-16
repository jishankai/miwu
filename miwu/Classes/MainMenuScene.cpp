//
//  MainMenuScene.cpp
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#include "MainMenuScene.h"
#include "MainMenuSceneLoader.h"

#include "NormalGameScene.h"
#include "MouseGameScene.h"

#include "EquipLoader.h"
#include "ArmyLoader.h"
#include "OthersLoader.h"
#include "EventLoader.h"
#include "RewardLoader.h"
#include "ShareLoader.h"
#include "AbilityLoader.h"
#include "ProcessLoader.h"
#include "MedalLoader.h"
#include "ShopLoader.h"
#include "Shop.h"
#include "GachaLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

MainMenuScene* MainMenuScene::sharedInstance = NULL;

MainMenuScene* MainMenuScene::sharedScene()
{
    return sharedInstance;
}

CCScene* MainMenuScene::scene()
{
    CCScene* scene = CCScene::create();
    sharedInstance = MainMenuSceneLoader::load();
    
    scene->addChild(sharedInstance);
    
    return scene;
    /*
    CCScene* scene = CCScene::create();
    
    MainMenuScene* layer = MainMenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
     */
}

bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    /*
    CCSprite* pNormalSprite = CCSprite::createWithSpriteFrameName("tx_miao.png");
    CCSprite* pSelectedSprite = CCSprite::createWithSpriteFrameName("tx_miao.png");
     */
    /*
    CCLabelTTF* pNormalGameLabel = CCLabelTTF::create();
    CCString* pNormalGameStr = CCString::createWithFormat("普通关卡");
    pNormalGameLabel->setString(pNormalGameStr->getCString());

    CCLabelTTF* pMouseGameLabel = CCLabelTTF::create();
    CCString* pMouseGameStr = CCString::createWithFormat("大嘴关卡");
    pMouseGameLabel->setString(pMouseGameStr->getCString());
    /*
    CCMenuItemSprite *pStartSprite = CCMenuItemSprite::create(
                                                          pNormalSprite,
                                                          pSelectedSprite,
                                                          this,
                                                          menu_selector(MainMenuScene::pressedPlay));
     */
    /*
    CCMenuItemLabel *pNormalGameSprite = CCMenuItemLabel::create(pNormalGameLabel, this, menu_selector(MainMenuScene::pressedPlay));
    CCMenuItemLabel *pMouseGameSprite = CCMenuItemLabel::create(pMouseGameLabel, this, menu_selector(MainMenuScene::pressedPlayMouseGame));
    
	pNormalGameSprite->setPosition(ccp(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height*2/3));
    
    pMouseGameSprite->setPosition(ccp(origin.x + visibleSize.width/2,
                                       origin.y + visibleSize.height/3));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pNormalGameSprite, pMouseGameSprite, NULL);
    pMenu->setPosition(CCPointZero);
    //CCLayerColor* pColorLayer = CCLayerColor::create(ccc4(0, 0, 0, 0));
    //this->addChild(pColorLayer);
    this->addChild(pMenu, 1);
    */
    return true;
}

void MainMenuScene::onEnter()
{
    CCLayer::onEnter();
    
    CCNode* gacha = GachaLoader::load();
    gacha->setAnchorPoint(CCPointZero);
    gacha->setPosition(CCPointZero);
    this->addChild(gacha);
    
    // Make sure touches are enabled
    this->setTouchEnabled(true);
}

bool MainMenuScene::onAssignCCBCustomProperty(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::extension::CCBValue *pCCBValue)
{
    return false;
}

bool MainMenuScene::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    /*
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "army", CCSprite*, this->army);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "coin", CCSprite*, this->coin);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "equip", CCSprite*, this->equip);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "event", CCSprite*, this->event);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "level", CCSprite*, this->level);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "medal", CCSprite*, this->medal);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "miao", CCSprite*, this->miao);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "others", CCSprite*, this->others);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "reward", CCSprite*, this->reward);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ring", CCSprite*, this->ring);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "share", CCSprite*, this->share);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "shop", CCSprite*, this->shop);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "treasure", CCSprite*, this->treasure);
    */
    return false;
}

void MainMenuScene::pressedPlay(cocos2d::CCObject *pSender)
{
    CCScene* pGameScene = NormalGameScene::scene();
    CCDirector::sharedDirector()->replaceScene(pGameScene);
}

void MainMenuScene::pressedPlayMouseGame(cocos2d::CCObject *pSender)
{
    CCScene* pGameScene = MouseGameScene::scene();
    CCDirector::sharedDirector()->replaceScene(pGameScene);
}

void MainMenuScene::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool MainMenuScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch = pTouch;//(CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocation();
    
    //CCRect* pOthersTextureRect = new CCRect(others->getPositionX(), others->getPositionY(), others->getContentSize().width, others->getContentSize().height);
    CCRect* pOthersTextureRect = new CCRect(398, 5, 48, 48);
    if (pOthersTextureRect->containsPoint(touchLocation)) {
        /*
        CCImage* image = new CCImage();
        image->autorelease();
        image->initWithImageFile("others.png");
        CCTexture2D* texture = new CCTexture2D();
        texture->autorelease();
        texture->initWithImage(image);
        CCSprite* sprite = CCSprite::createWithTexture(texture);
        sprite->setAnchorPoint(ccp(0,0));
        sprite->setPosition(ccp(0,0));
        this->addChild(sprite, 100);
         */
        
        CCLOG("Others Layer");
        CCNode* others = OthersLoader::load();
        others->setAnchorPoint(CCPointZero);
        others->setPosition(CCPointZero);
        this->addChild(others);
        return true;
    }
    CCRect* pEventTextureRect = new CCRect(340, 5, 48, 48);
    if (pEventTextureRect->containsPoint(touchLocation)) {
        CCLOG("Event Layer");
        CCNode* event = EventLoader::load();
        event->setAnchorPoint(CCPointZero);
        event->setPosition(CCPointZero);
        this->addChild(event);
        return true;
    }
    CCRect* pRewardTextureRect = new CCRect(93, 5, 48, 48);
    if (pRewardTextureRect->containsPoint(touchLocation)) {
        CCLOG("Reward Layer");
        CCNode* reward = RewardLoader::load();
        reward->setAnchorPoint(CCPointZero);
        reward->setPosition(CCPointZero);
        this->addChild(reward);
        return true;
    }
    CCRect* pShopTextureRect = new CCRect(36, 5, 48, 48);
    if (pShopTextureRect->containsPoint(touchLocation)) {
        CCLOG("Shop Layer");
        CCNode* shop = ShopLoader::load();
        shop->setAnchorPoint(CCPointZero);
        shop->setPosition(CCPointZero);
        this->addChild(shop);
        return true;
    }
    CCRect* pArmyTextureRect = new CCRect(427, 110, 48, 48);
    if (pArmyTextureRect->containsPoint(touchLocation)) {
        CCNode* army = ArmyLoader::load();
        army->setAnchorPoint(CCPointZero);
        army->setPosition(CCPointZero);
        this->addChild(army);
        CCLOG("Army Layer");
        return true;

    }
    CCRect* pEquipTextureRect = new CCRect(427, 170, 48, 48);
    if (pEquipTextureRect->containsPoint(touchLocation)) {
        CCNode* equip = EquipLoader::load();
        equip->setAnchorPoint(CCPointZero);
        equip->setPosition(CCPointZero);
        this->addChild(equip);
        CCLOG("Equip Layer");
        return true;
    }
    CCRect* pRingTextureRect = new CCRect(296, 276, 86, 32);
    if (pRingTextureRect->containsPoint(touchLocation)) {
        CCLOG("Ring Layer");
        CCNode* shopNode = ShopLoader::load();
        Shop* shop = dynamic_cast<Shop*>(shopNode);
        shop->setAnchorPoint(CCPointZero);
        shop->setPosition(CCPointZero);
        shop->ring->setVisible(true);
        this->addChild(shop);
        return true;
    }
    CCRect* pTreasureTextureRect = new CCRect(196, 276, 86, 32);
    if (pTreasureTextureRect->containsPoint(touchLocation)) {
        CCLOG("Treasure Layer");
        CCNode* shopNode = ShopLoader::load();
        Shop* shop = dynamic_cast<Shop*>(shopNode);
        shop->setAnchorPoint(CCPointZero);
        shop->setPosition(CCPointZero);
        shop->treasure->setVisible(true);
        this->addChild(shop);
        return true;
    }
    CCRect* pCoinTextureRect = new CCRect(96, 276, 86, 32);
    if (pCoinTextureRect->containsPoint(touchLocation)) {
        CCLOG("Coin Layer");
        CCNode* shopNode = ShopLoader::load();
        Shop* shop = dynamic_cast<Shop*>(shopNode);
        shop->setAnchorPoint(CCPointZero);
        shop->setPosition(CCPointZero);
        shop->coin->setVisible(true);
        this->addChild(shop);
        return true;
    }
    CCRect* pAbilityTextureRect = new CCRect(0, 271, 86, 48);
    if (pAbilityTextureRect->containsPoint(touchLocation)) {
        CCLOG("Ability Layer");
        CCNode* ability = AbilityLoader::load();
        ability->setAnchorPoint(CCPointZero);
        ability->setPosition(CCPointZero);
        this->addChild(ability);
        return true;
    }
    CCRect* pMedalTextureRect = new CCRect(0, 217, 42, 48);
    if (pMedalTextureRect->containsPoint(touchLocation)) {
        CCLOG("Medal Layer");
        CCNode* medal = MedalLoader::load();
        medal->setAnchorPoint(CCPointZero);
        medal->setPosition(CCPointZero);
        this->addChild(medal);
        return true;
    }
    CCRect* pProcessTextureRect = new CCRect(72, 183, 90, 70);
    if (pProcessTextureRect->containsPoint(touchLocation)) {
        CCLOG("Process Layer");
        CCNode* process = ProcessLoader::load();
        process->setAnchorPoint(CCPointZero);
        process->setPosition(CCPointZero);
        this->addChild(process);
        return true;
    }
    CCRect* pShareTextureRect = new CCRect(0, 129, 38, 76);
    if (pShareTextureRect->containsPoint(touchLocation)) {
        CCLOG("Share Layer");
        CCNode* share = ShareLoader::load();
        share->setAnchorPoint(CCPointZero);
        share->setPosition(CCPointZero);
        this->addChild(share);
        return true;
    }
    
    return false;
}

/*
void MainMenuScene::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint touchLocation = touch->getLocationInView();
    CCRect* pOthersTextureRect = new CCRect(398, 5, 48, 48);
    if (pOthersTextureRect->containsPoint(touchLocation)) {
        CCLOG("Others Layer");
    }
    CCRect* pEventTextureRect = new CCRect(340, 5, 48, 48);
    if (pEventTextureRect->containsPoint(touchLocation)) {
        CCLOG("Event Layer");
    }
    CCRect* pRewardTextureRect = new CCRect(93, 5, 48, 48);
    if (pRewardTextureRect->containsPoint(touchLocation)) {
        CCLOG("Reward Layer");
    }
    CCRect* pShopTextureRect = new CCRect(36, 5, 48, 48);
    if (pShopTextureRect->containsPoint(touchLocation)) {
        CCLOG("Shop Layer");
    }
    CCRect* pArmyTextureRect = new CCRect(427, 110, 48, 48);
    if (pArmyTextureRect->containsPoint(touchLocation)) {
        CCLOG("Army Layer");
    }
    CCRect* pEquipTextureRect = new CCRect(427, 170, 48, 48);
    if (pEquipTextureRect->containsPoint(touchLocation)) {
        CCLOG("Equip Layer");
    }
    CCRect* pRingTextureRect = new CCRect(296, 276, 86, 32);
    if (pRingTextureRect->containsPoint(touchLocation)) {
        CCLOG("Ring Layer");
    }
    CCRect* pTreasureTextureRect = new CCRect(196, 276, 86, 32);
    if (pTreasureTextureRect->containsPoint(touchLocation)) {
        CCLOG("Treasure Layer");
    }
    CCRect* pCoinTextureRect = new CCRect(96, 276, 86, 32);
    if (pCoinTextureRect->containsPoint(touchLocation)) {
        CCLOG("Coin Layer");
    }
    CCRect* pMiaoTextureRect = new CCRect(0, 271, 86, 48);
    if (pMiaoTextureRect->containsPoint(touchLocation)) {
        CCLOG("Miao Layer");
    }
    CCRect* pMedalTextureRect = new CCRect(0, 217, 42, 48);
    if (pMedalTextureRect->containsPoint(touchLocation)) {
        CCLOG("Medal Layer");
    }
    CCRect* pLevelTextureRect = new CCRect(72, 183, 90, 70);
    if (pLevelTextureRect->containsPoint(touchLocation)) {
        CCLOG("Level Layer");
    }
    CCRect* pShareTextureRect = new CCRect(0, 129, 38, 76);
    if (pShareTextureRect->containsPoint(touchLocation)) {
        CCLOG("Share Layer");
    }
    //dragon->setXTarget(touchLocation.x);
}
*/