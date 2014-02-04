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
    cocos2d::CCSprite* level1;
    cocos2d::CCSprite* level2;
    cocos2d::CCSprite* level3;
    cocos2d::CCSprite* level4;
    cocos2d::CCSprite* level5;
    cocos2d::CCSprite* level6;
    cocos2d::CCSprite* level7;
    cocos2d::CCSprite* level8;
    cocos2d::CCSprite* level9;
    cocos2d::CCSprite* level10;
    cocos2d::CCSprite* level11;
    cocos2d::CCSprite* level12;
    cocos2d::CCSprite* level13;
    cocos2d::CCSprite* level14;
    cocos2d::CCSprite* level15;
    cocos2d::CCSprite* level16;
    cocos2d::CCSprite* level17;
    cocos2d::CCSprite* level18;
    cocos2d::CCSprite* level19;
    cocos2d::CCSprite* level20;
    cocos2d::CCSprite* level21;
    cocos2d::CCSprite* level22;
    cocos2d::CCSprite* level23;
    cocos2d::CCSprite* level24;
    cocos2d::CCSprite* level25;
    cocos2d::CCSprite* level26;
    cocos2d::CCSprite* level27;
    cocos2d::CCSprite* level28;
    cocos2d::CCSprite* level29;
    cocos2d::CCSprite* level30;
    cocos2d::CCSprite* level31;
    cocos2d::CCSprite* level32;
    cocos2d::CCSprite* level33;
    cocos2d::CCSprite* level34;
    cocos2d::CCSprite* level35;
    cocos2d::CCSprite* level36;
    cocos2d::CCSprite* level37;
    cocos2d::CCSprite* level38;
    cocos2d::CCSprite* level39;
    cocos2d::CCSprite* level40;
    cocos2d::CCSprite* level41;
    cocos2d::CCSprite* level42;
    cocos2d::CCSprite* level43;
    cocos2d::CCSprite* level44;
    cocos2d::CCSprite* level45;
    cocos2d::CCSprite* level46;
    cocos2d::CCSprite* level47;
    cocos2d::CCSprite* level48;
    cocos2d::CCSprite* level49;
    cocos2d::CCSprite* level50;
    cocos2d::CCSprite* level51;
    cocos2d::CCSprite* level52;
    cocos2d::CCSprite* level53;
    cocos2d::CCSprite* level54;
    cocos2d::CCSprite* level55;
    cocos2d::CCSprite* level56;
    cocos2d::CCSprite* level57;
    cocos2d::CCSprite* level58;
    cocos2d::CCSprite* level59;
    cocos2d::CCSprite* level60;
    cocos2d::CCSprite* level61;
    cocos2d::CCSprite* level62;
    cocos2d::CCSprite* level63;
    cocos2d::CCSprite* level64;
    cocos2d::CCSprite* level65;
    cocos2d::CCSprite* level66;
    cocos2d::CCSprite* level67;
    cocos2d::CCSprite* level68;
    cocos2d::CCSprite* level69;
    cocos2d::CCSprite* level70;
    cocos2d::CCSprite* level71;
    cocos2d::CCSprite* level72;
    cocos2d::CCSprite* level73;
    cocos2d::CCSprite* level74;
    cocos2d::CCSprite* level75;
    cocos2d::CCSprite* level76;
    cocos2d::CCSprite* level77;
    cocos2d::CCSprite* level78;
    cocos2d::CCSprite* level79;
    cocos2d::CCSprite* level80;
    cocos2d::CCSprite* level81;
    cocos2d::CCSprite* level82;
    cocos2d::CCSprite* level83;
    cocos2d::CCSprite* level84;
    cocos2d::CCSprite* level85;
    cocos2d::CCSprite* level86;
    cocos2d::CCSprite* level87;
    cocos2d::CCSprite* level88;
    cocos2d::CCSprite* level89;
    cocos2d::CCSprite* level90;
    cocos2d::CCSprite* level91;
    cocos2d::CCSprite* level92;
    cocos2d::CCSprite* level93;
    cocos2d::CCSprite* level94;
    cocos2d::CCSprite* level95;
    cocos2d::CCSprite* level96;
    cocos2d::CCSprite* level97;
    cocos2d::CCSprite* level98;
    cocos2d::CCSprite* level99;
    cocos2d::CCSprite* level100;
    cocos2d::CCSprite* level101;
    cocos2d::CCSprite* level102;
    cocos2d::CCSprite* level103;
    cocos2d::CCSprite* level104;
    cocos2d::CCSprite* level105;
    cocos2d::CCSprite* level106;
    cocos2d::CCSprite* level107;
    cocos2d::CCSprite* level108;
    cocos2d::CCSprite* level109;
    cocos2d::CCSprite* level110;
    cocos2d::CCSprite* level111;
    cocos2d::CCSprite* level112;
    cocos2d::CCSprite* level113;
    cocos2d::CCSprite* level114;
    cocos2d::CCSprite* level115;
    cocos2d::CCSprite* level116;
    cocos2d::CCSprite* level117;
    cocos2d::CCSprite* level118;
    cocos2d::CCSprite* level119;
    cocos2d::CCSprite* level120;
    
public:
    static int mapType;
    static int levelNum;
    virtual void onEnter();
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    void initNormalGame();
    void initMouseGame();
    void sendStartRequest();

    void setProcess();
    void setStars(cocos2d::CCSprite* l, int s);
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Process, create);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void onStartRequestCompleted(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
};

#endif /* defined(__miwu__Process__) */
