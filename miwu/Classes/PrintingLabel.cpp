//
//  PrintingLabel.cpp
//  miwu
//
//  Created by wwm on 13-10-20.
//
//

#include "PrintingLabel.h"
#include <StaticData.h>
#include <Toolkit.h>
#include <stdlib.h>

USING_NS_CC;
using namespace std;

PrintingLabel* PrintingLabel::create(string& type, const char* fnt, float delay)
{
    PrintingLabel* printingLabel = new PrintingLabel();
    if (printingLabel && printingLabel->init(type, fnt,  delay))
    {
        printingLabel->autorelease();
        return printingLabel;
    }
    else
    {
        delete printingLabel;
        printingLabel = NULL;
        return NULL;
    }
}

bool PrintingLabel::init(string& type, const char *fnt, float delay)
{
    this->type = type;
    this->fnt = fnt;
    this->delay = delay;
    complete = false;
    count = 0;
    string totalFormat = type + "_total";
    total = STATIC_DATA_INT(totalFormat.c_str());
    setLabel();
    printingHandler();
    return true;
}

void PrintingLabel::setLabel()
{
    string countStr;
    Toolkit::intTostring(count, countStr);
    string textFormat = type + countStr;
    const char* text = STATIC_DATA_STRING(textFormat.c_str());
    label = CCLabelTTF::create(text, fnt, 14);
    this->addChild(label);
    label->setPosition(CCPointZero);
    label->setAnchorPoint(CCPointZero);
}

void PrintingLabel::printingHandler()
{
    CCDelayTime* sleep = CCDelayTime::create(delay);
    CCCallFuncND* labelUpdate = CCCallFuncND::create(this, callfuncND_selector(PrintingLabel::labelUpdateHandler), NULL);
    CCSequence* seq = CCSequence::create(sleep, labelUpdate);
    repeat = CCRepeat::create(seq, total);
    
    this->runAction(repeat);
}

                                                    
void PrintingLabel::labelUpdateHandler(CCNode* sender)
{
    if (count == total-1)
    {
        complete = true;
        this->stopAction(repeat);
        return;
    }
    count++;
    string countStr;
    Toolkit::intTostring(count, countStr);
    string textFormat = type + countStr;
    const char* text = STATIC_DATA_STRING(textFormat.c_str());
    label->setString(text);
    label->setPosition(CCPointZero);
    label->setAnchorPoint(CCPointZero);
}

void PrintingLabel::displayComplete()
{
    count = total - 2;
    complete = true;
    labelUpdateHandler(NULL);
}

void PrintingLabel::setString(CCString* text)
{
    
}

PrintingLabel::~PrintingLabel(void)
{
    
}



