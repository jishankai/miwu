//
//  Load.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__Load__
#define __miwu__Load__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "LayerWithDialog.h"

struct CQPlayer {
    int playerId;
    std::string playerName;
    int combats;
    int stars;
    int level;
};

class Load : public cocos2d::CCLayer
{
private:
    
public:
    static std::string sharedSessionId;
    static struct CQPlayer sharedPlayer;
    static cocos2d::CCNode* sharedInstance;
    static cocos2d::CCScene* scene();
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Load, create);
    
    void onLoginRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
    void onRegisterRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
    void onPlayerRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
};

#endif /* defined(__miwu__Load__) */
