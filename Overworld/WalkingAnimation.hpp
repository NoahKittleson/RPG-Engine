//
//  WalkingAnimation.hpp
//  Overworld
//
//  Created by Noah Kittleson on 6/3/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "GraphicsComponent.hpp"

class WalkingAnimation : public GraphicsComponent
{
public:
	WalkingAnimation(const sf::Texture& texture, sf::Vector2f position, );
	virtual void update(MapObject& obj, float elapsed) override;

	
private:
	enum Direction {Up, Down, Left, Right, Stand};
	Direction walkingState;
};
