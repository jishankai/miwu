//
//  DrawLineLayer.h
//  miwu
//
//  Created by wwm on 13-10-28.
//
//

#ifndef __miwu__DrawLineLayer__
#define __miwu__DrawLineLayer__

#include <iostream>
#include "cocos2d.h"

class DrawLineLayer : public cocos2d::CCLayer
{
    public:
        static DrawLineLayer* create(cocos2d::CCPoint& start, cocos2d::CCPoint& end);
        bool init(cocos2d::CCPoint& start, cocos2d::CCPoint& end);
        virtual void draw();
    
    private:
        cocos2d::CCPoint start;
        cocos2d::CCPoint end;
};

#endif /* defined(__miwu__DrawLineLayer__) */
