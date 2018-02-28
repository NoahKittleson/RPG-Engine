//
//  DelayedAnimComponent.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "DelayedAnimation.hpp"

DelayedAnimation::DelayedAnimation(const sf::Texture& t, sf::Vector2f pos, float timePerFrame, sf::Vector2i frame, float repeatDelay)
: AnimatedComponent(t, pos, timePerFrame, frame), repeatDelay(repeatDelay)
{
	setOrigin(frame.x/2, frame.y/2);
}

void DelayedAnimation::update(float elapsed)
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
            if (atEnd()) {
                waiting = true;
				nextFrame();
				return;
            }
            nextFrame();
        }
    }
}
