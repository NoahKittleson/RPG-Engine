//
//  MapSprite.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

//class MapSprite : public sf::Sprite
//{
//public:
//    MapSprite(sf::IntRect, float timePerFrame = 0);
//    
//    int getBase() const;
//    void drawBase(sf::RenderWindow &rw) const;
//    virtual void update(float elapsed);
//    
//protected:
//    void animate(float elapsed);
//    void nextFrame();
//    
//    float timePerFrame;
//    float totalElapsed;
//    sf::IntRect frameSize;
//};

#include "AnimatedSprite.h"

class MapSprite : public AnimatedSprite
{
public:
    MapSprite(sf::Vector2i frameSize, float timePerFrame, const sf::Texture& texture, float repeatDelay = 0);

    int getBase() const;
    void drawBase(sf::RenderWindow &rw) const;
};






