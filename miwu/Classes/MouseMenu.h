//
//  MouseMenu.h
//  miwu
//
//  Created by long on 2013-03-01.
//
//

#ifndef __miwu__MouseMenu__
#define __miwu__MouseMenu__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Level.h"

class MouseMenu : public cocos2d::CCLayer
{
private:
    cocos2d::CCLayer* levelLayer;
    cocos2d::CCLayer* backgroundLayer;
    Level* level;
    bool init();
    
public:
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MouseMenu, create);
    
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__miwu__MouseMenu__) */
