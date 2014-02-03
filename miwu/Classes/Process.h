//
//  Process.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__Process__
#define __miwu__Process__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "LayerWithDialog.h"

class Process : public LayerWithDialog
{
private:
    cocos2d::CCSprite* level_ri;
    cocos2d::CCSprite* level_west;
    cocos2d::CCSprite* level_tale;
    cocos2d::CCSprite* level_cn;
    cocos2d::CCSprite* level_evil;
public:
    static int mapType;
    static int levelNum;
    virtual void onEnter();
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    void initNormalGame();
    void initMouseGame();
    void sendStartRequest();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Process, create);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void onStartRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
};

#endif /* defined(__miwu__Process__) */
