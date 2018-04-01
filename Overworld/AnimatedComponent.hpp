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
    AnimatedComponent(const sf::Texture&, sf::Vector2f position, float timePerFrame, sf::Vector2i frame);
    virtual void update(float elapsed) override;
    virtual void addTime(float delta) override;
	bool atEnd();
	void setTexture(const sf::Texture& texture);
    
protected:
    float totalElapsed = 0;
    const float timePerFrame;
    sf::IntRect frameSize;
    
    void nextFrame();
	
};
