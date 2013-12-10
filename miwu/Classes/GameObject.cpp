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

void GameObject::reboundHeartHandler(GameObject* gameObject)
{
    
}

bool GameObject::hurtToOther(float atk)
{
    return false;
}

void GameObject::atkHandler(float atk, GameObject* gameObject)
{
    reboundHeartHandler(gameObject);
    if (hurtToOther(atk))
    {
        return;
    }
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
        if (bloodBar == NULL)
        {
            return;
        }
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

void GameObject::reboundedHeartedHandler()
{
    
}



