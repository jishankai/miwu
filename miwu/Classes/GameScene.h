//
//  GameScene.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__GameScene__
#define __miwu__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"

class GameScene : public cocos2d::CCLayer, public cocos2d::extension::CCBMemberVariableAssigner
{
private:
    
public:
    cocos2d::CCNode* background;
    cocos2d::CCNode* menu;
    cocos2d::CCNode* status;
    cocos2d::CCLayer* backgroundLayer;
    cocos2d::CCLayer* statusLayer;
    cocos2d::CCLayer* menuLayer;
    
    static GameScene* sharedInstance;
    
    static GameScene* sharedScene();
    
    //virtual static cocos2d::CCScene* scene();
    
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameScene, create);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
    void handleGameOver();
    void handleLevelComplete();
  

};

#endif /* defined(__miwu__GameScene__) */
