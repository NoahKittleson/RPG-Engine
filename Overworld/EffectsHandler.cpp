//
//  EffectsHandler.cpp
//  BattleMode
//
//  Created by Noah Kittleson on 5/27/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "EffectsHandler.h"

#define ZOOM_SPEED_X 1024
#define ZOOM_SPEED_Y 768
#define ZOOM_POS_ABOVE_MIDDLE 150
#define SPRITE_MOVEMENT_FACTOR 2.0f


void EffectsHandler::Update(float elapsed, sf::View &view, sf::RenderWindow &rw)
{
    if (effectsList.empty())
    {
        return;
    }
    
    for (std::list<Effect>::iterator it = effectsList.begin(); it != effectsList.end(); it++)
    {
        switch (*it)
        {
            case ZoomIn:
                if (view.getSize().x > rw.getSize().x/2)
                {
                    view.setSize(view.getSize().x-(ZOOM_SPEED_X*elapsed), view.getSize().y-(ZOOM_SPEED_Y*elapsed));
                    view.setCenter(view.getCenter().x, view.getCenter().y-(ZOOM_POS_ABOVE_MIDDLE*elapsed));
                }
                else effectsList.erase(it++);
                break;
                
            case ZoomOut:
                if (view.getSize().x <= rw.getDefaultView().getSize().x &&
                    view.getSize().y <= rw.getDefaultView().getSize().y)	//seems silly to take &window just for getdefaultview.
                {
                    view.setSize(view.getSize().x+(ZOOM_SPEED_X*elapsed), view.getSize().y+(ZOOM_SPEED_Y*elapsed));
                    view.setCenter(view.getCenter().x, view.getCenter().y+(ZOOM_POS_ABOVE_MIDDLE*elapsed));
                }
                else
                {
                    effectsList.erase(it++);
                    view = rw.getDefaultView();
                }
                break;
                
            case Pause:
                totalelapsed += elapsed;
                if (totalelapsed > 1.0f)
                {
                    effectsList.erase(it++);
                    totalelapsed = 0;
                }
                break;
                
            default:
                break;
        }
    }
}

void EffectsHandler::addEffect(EffectsHandler::Effect neweffect)
{
    //if it already contains it, return
    if(std::find(effectsList.begin(), effectsList.end(), neweffect) != effectsList.end())
    {
        return;
    }
    //if they try to add a new effect during a pause, return
    if (*effectsList.begin() == Pause)
    {
        return;
    }
    //if ZoomIn and ZoomOut are both active, throw away the old one.
    if (neweffect == ZoomIn)
    {
        auto target = std::find(effectsList.begin(), effectsList.end(), ZoomOut);
        if (target != effectsList.end())
        {
            effectsList.erase(target);
        }
    }
    if (neweffect == ZoomOut)
    {
        auto target = std::find(effectsList.begin(), effectsList.end(), ZoomIn);
        if (target != effectsList.end())
        {
            effectsList.erase(target);
        }
    }
    
    //add the new Effect
    effectsList.push_back(neweffect);
}

void EffectsHandler::clearAll()
{
    effectsList.clear();
}

bool EffectsHandler::isBusy()
{
    return !(effectsList.empty() && MoveInfoList.empty());		//has items = not empty = busy = true
}

void EffectsHandler::UpdateSprites(float elapsed)               //this will decrease sprite movement as it gets further
{
    for (std::list<MoveInfo>::iterator it = MoveInfoList.begin(); it != MoveInfoList.end();)    //manual iteration
    {
        sf::Vector2f moveVector = (*it).MoveToPos-(*it).OriginalPos;
        if (std::abs((*it).OriginalPos.x - (*it).SprPtr->getPosition().x) >=
            std::abs((*it).OriginalPos.x - (*it).MoveToPos.x))
        {
            moveVector.x = 0;
        }
        if (std::abs((*it).OriginalPos.y - (*it).SprPtr->getPosition().y) >=
            std::abs((*it).OriginalPos.y - (*it).MoveToPos.y))
        {
            moveVector.y = 0;
        }
        
        (*it).SprPtr->move(moveVector * elapsed * SPRITE_MOVEMENT_FACTOR);
        if (moveVector.x == 0 && moveVector.y == 0)
        {
            MoveInfoList.erase(it++);
        }
        else it++;
    }
}

void EffectsHandler::addSprite(AnimatedSprite* zen, sf::Vector2f vek)
{
    MoveInfo addme;
    addme.SprPtr = zen;
    addme.MoveToPos = vek;
    addme.OriginalPos = (*zen).getPosition();
    MoveInfoList.push_back(addme);
}
/*
 void EffectsHandler::addAnimation(AnimatedSprite add)
 {
 AnimationList.push_back(add);
 }
 
 void EffectsHandler::UpdateAnimation(float elapsed, sf::RenderWindow &rw)
 {
 for (std::list<AnimatedSprite>::iterator it = AnimationList.begin(); it != AnimationList.end(); it++)
 {
 (*it).animate(elapsed, rw);
 }
 }*/

void EffectsHandler::fadeOut(sf::RenderWindow &rw)
{
    sf::Texture ScreenCap;
    ScreenCap.loadFromImage(rw.capture());
    sf::Sprite SpleenCrap;
    SpleenCrap.setTexture(ScreenCap);

    sf::Clock timer;
    float opacity = 0;
    
    while (opacity < 255) {
        rw.clear();
        opacity += timer.restart().asSeconds() * 100;
        SpleenCrap.setColor(sf::Color(0,0,0,opacity));
        
        rw.draw(SpleenCrap);
        rw.display();
    }
}

void EffectsHandler::fadeIn(sf::RenderWindow &rw)
{
    
}








