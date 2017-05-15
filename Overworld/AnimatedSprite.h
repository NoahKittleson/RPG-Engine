//
//  AnimatedSprite.h
//  BattleMode
//
//  Created by Noah Kittleson on 6/2/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class AnimatedSprite : public sf::Sprite
{
public:
    AnimatedSprite(const sf::Vector2i& frameSize, float timePerFrame, const sf::Texture&, float repeatDelay = 0.f);
    AnimatedSprite(const AnimatedSprite& other);
    
    void update(float elapsed);
    bool compare(const sf::Texture*);                         //true if same texture, false if not.
    char isOnFrame();
    
protected:
    void next_frame();
    
    const sf::IntRect _frameSize;
    const float repeatDelay = 0.f;
    
    const float _timePerFrame;
    float _totalelapsed = 0;
};


//THINGS TO DO:
//1. Have this class (or a similar one) used by both battle sprites and map sprites (all animated sprites).
