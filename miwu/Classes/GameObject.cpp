//
//  GameObject.cpp
//  miwu
//
//  Created by Ji Shankai on 13-5-28.
//
//

#include "GameObject.h"

bool GameObject::checkIsCollision(GameObject *gameObject)
{
    int differenceX = abs(getPositionX() - gameObject->getPositionX());
    if (differenceX <= radius())
    {
        return true;
    }
    return false;
}

void GameObject::atkHandler(float atk)
{
    hp -= atk;
    if (hp <= 0)
    {
        deadHandler();
//        bloodBar->setVisible(false);
    }
    else if (hp >= maxHp)
    {
        return;
    }
    else
    {
        bloodBar->setScaleX(0.3f*hp/maxHp);
    }
}

void GameObject::resetCurActionCount()
{
    curActionCount = 0;
}

bool GameObject::stopAction()
{
    return curActionCount == actionRange;
}

void GameObject::stop()
{
    xSpeed = 0;
}



