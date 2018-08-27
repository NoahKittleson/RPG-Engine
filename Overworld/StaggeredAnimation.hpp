//
//  StaggeredAnimation.hpp
//  Overworld
//
//  Created by Noah Kittleson on 8/26/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "AnimatedComponent.hpp"
#include "IterVector.hpp"

class StaggeredAnimation : public AnimatedComponent
{
public:
	StaggeredAnimation(const sf::Texture&, sf::Vector2f, IterVector<float> frameLengths, sf::Vector2i frame);
	virtual void update(float elapsed) override;
	std::unique_ptr<GraphicsComponent> getCopy() override;
	
protected:
	IterVector<float> frameLengths;
};
