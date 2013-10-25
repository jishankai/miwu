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
    
public:
    virtual void onEnter();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Process, create);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__miwu__Process__) */
