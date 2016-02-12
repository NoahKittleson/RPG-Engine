//
//  EffectsHandler.h
//  BattleMode
//
//  Created by Noah Kittleson on 5/27/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "AnimatedSprite.h"

class EffectsHandler
{
public:
    enum Effect {ZoomIn, ZoomOut, Pause};
    
    bool isBusy();
    void clearAll();            //only clears effects currently...
    void addEffect(Effect);
    void Update(float elapsed, sf::View &view, sf::RenderWindow &rw);
    
    void addSprite(AnimatedSprite*, sf::Vector2f);
    void UpdateSprites(float elapsed);
    
    //void addAnimation(AnimatedSprite);
    void UpdateAnimation(float elapsed, sf::RenderWindow &rw);
    
    void fadeOut(sf::RenderWindow &rw);
    void fadeIn(sf::RenderWindow &rw);
    
    
private:
    std::list<Effect> effectsList;
    float totalelapsed = 0;                 //what is this used for, exactly?  I'm sure it's used but the name should be more specific...
    
    //non-effect related
    struct MoveInfo
    {
        AnimatedSprite* SprPtr;
        sf::Vector2f MoveToPos;
        sf::Vector2f OriginalPos;
    };
    std::list<MoveInfo> MoveInfoList;
    
    //std::list<AnimatedSprite> AnimationList;
};

