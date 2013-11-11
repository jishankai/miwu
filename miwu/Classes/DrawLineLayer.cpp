//
//  DrawLineLayer.cpp
//  miwu
//
//  Created by wwm on 13-10-28.
//
//

#include "DrawLineLayer.h"

USING_NS_CC;

DrawLineLayer* DrawLineLayer::create(CCPoint &start, CCPoint &end)
{
    DrawLineLayer* drawLineLayer = new DrawLineLayer();
    if (drawLineLayer && drawLineLayer->init(start, end))
    {
        drawLineLayer->autorelease();
        return drawLineLayer;
    }
    else
    {
        delete drawLineLayer;
        drawLineLayer = NULL;
        return NULL;
    }
}

bool DrawLineLayer::init(CCPoint &start, CCPoint &end)
{
    this->start = start;
    this->end = end;
    return true;
}

void DrawLineLayer::draw()
{
    glEnable(GL_LINE_LOOP);
    glLineWidth(4.0f);
    ccDrawColor4B(255, 0, 0, 255);
    ccDrawLine(start, end);
    
    ccPointSize(4.0f);
    ccDrawColor4B(0, 255, 0, 255);
    ccDrawPoint(start);
    
    ccPointSize(4.0f);
    ccDrawColor4B(0, 0, 255, 255);
    ccDrawPoint(end);
}