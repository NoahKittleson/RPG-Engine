//
//  AnimatedComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "GraphicsComponent.hpp"

class AnimatedComponent : public GraphicsComponent
{
public:
    AnimatedComponent(float timePerFrame, sf::Vector2i frame);
    virtual void update(MapSprite& spr, float elapsed) override;
    
protected:
    float totalElapsed = 0;
    const float timePerFrame;
    sf::IntRect frameSize;
    
    void nextFrame(MapSprite& spr);
    bool atEnd(MapSprite& spr);
};
