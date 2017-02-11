//
//  MapSprite.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class MapSprite : public sf::Sprite
{
public:
    int getBase() const;
    void drawBase(sf::RenderWindow &rw);
    virtual void update(float elapsed);
    
protected:
    void animate(float elapsed);
    void nextFrame();
    
    float timePerFrame = 0.f;
    float totalElapsed = 0;
    sf::IntRect frameSize;
};
