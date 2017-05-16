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
    virtual void update(MapSprite& spr, float elapsed) override;
    
protected:
    float totalElapsed;
    float timePerFrame;
    sf::IntRect frameSize;
    
    void nextFrame(MapSprite& spr);
    bool atEnd(MapSprite& spr);
};
