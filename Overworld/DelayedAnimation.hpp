//
//  DelayedAnimComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "AnimatedComponent.hpp"

class DelayedAnimation :  public AnimatedComponent
{
public:
    DelayedAnimation(float timePerFrame, sf::Vector2i frame, float repeatDelay);
    virtual void update(MapSprite& spr, float elapsed) override;
    
protected:
    const float repeatDelay;
    bool waiting;
};
