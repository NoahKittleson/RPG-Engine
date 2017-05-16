//
//  AnimatedComponent.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "AnimatedComponent.hpp"

void AnimatedComponent::update(MapSprite& spr, float elapsed)
{
    totalElapsed += elapsed;
    while (totalElapsed >= timePerFrame) {
        totalElapsed -= timePerFrame;
        nextFrame(spr);
    }
}

void AnimatedComponent::nextFrame(MapSprite& spr)
{
    if (atEnd(spr)) {
        spr.setTextureRect(frameSize);
    }
    else spr.setTextureRect(sf::IntRect(spr.getTextureRect().left + frameSize.width,
                                        spr.getTextureRect().top,
                                        spr.getTextureRect().width,
                                        spr.getTextureRect().height ));
}

bool AnimatedComponent::atEnd(MapSprite& spr)
{
    return (spr.getTextureRect().left + frameSize.width >= spr.getTexture()->getSize().x);
}


