//
//  DelayedAnimComponent.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "DelayedAnimation.hpp"

DelayedAnimation::DelayedAnimation(float timePerFrame, sf::Vector2i frame, float repeatDelay)
: AnimatedComponent(timePerFrame, frame), repeatDelay(repeatDelay)
{
    
}

void DelayedAnimation::update(MapSprite &spr, float elapsed)
{
    totalElapsed += elapsed;
    if (waiting) {
        if (totalElapsed >= repeatDelay) {
            totalElapsed -= repeatDelay;
            waiting = false;
        }
    } else {
        while (totalElapsed >= timePerFrame) {
            totalElapsed -= timePerFrame;
            if (repeatDelay && atEnd(spr)) {
                waiting = true;
                return;
            }
            nextFrame(spr);
        }
    }
}
