//
//  PrintingLabel.h
//  miwu
//
//  Created by wwm on 13-10-20.
//
//

#ifndef __miwu__PrintingLabel__
#define __miwu__PrintingLabel__

#include <iostream>
#include "cocos2d.h"

class PrintingLabel : public cocos2d::CCNode
{
    public:
        static PrintingLabel* create(std::string& type, const char* fnt, float delay);
        bool init(std::string& type, const char* fnt, float delay);
        void setString(cocos2d::CCString* text);
        bool getComplete(){return complete;}
        void displayComplete();
        ~PrintingLabel(void);
    private:
        std::string type;
        const char* fnt;
        int delay;
        int count;
        int total;
        cocos2d::CCLabelTTF* label;
        bool complete;
        cocos2d::CCRepeat*  repeat;
    
        void setLabel();
        void printingHandler();
        void labelUpdateHandler(cocos2d::CCNode* sender);
};
#endif /* defined(__miwu__PrintingLabel__) */
