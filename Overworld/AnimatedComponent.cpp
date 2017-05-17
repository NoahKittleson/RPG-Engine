//
//  AnimatedComponent.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "AnimatedComponent.hpp"

AnimatedComponent::AnimatedComponent(sf::Texture& t, sf::Vector2f pos, float timePerFrame, sf::Vector2i frame)
: timePerFrame(timePerFrame), frameSize(0,0,frame.x, frame.y), GraphicsComponent(t, pos)
{
    
}

void AnimatedComponent::update(MapObject& obj, float elapsed)
{
    totalElapsed += elapsed;
    while (totalElapsed >= timePerFrame) {
        totalElapsed -= timePerFrame;
        nextFrame();
    }
}

void AnimatedComponent::nextFrame()
{
    if (atEnd()) {
        setTextureRect(frameSize);
    }
    else setTextureRect(sf::IntRect(getTextureRect().left + frameSize.width,
                                    getTextureRect().top,
                                    getTextureRect().width,
                                    getTextureRect().height ));
}

bool AnimatedComponent::atEnd()
{
    return (getTextureRect().left + frameSize.width >= getTexture()->getSize().x);
}


