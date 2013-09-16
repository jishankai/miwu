//
//  RewardLoader.h
//  miwu
//
//  Created by Ji Shankai on 13-6-8.
//
//

#ifndef __miwu__RewardLoader__
#define __miwu__RewardLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Reward.h"

class RewardLoader : public cocos2d::extension::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RewardLoader, loader);
    static cocos2d::CCNode* load();
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Reward);
    
};


#endif /* defined(__miwu__RewardLoader__) */
