//
//  WalkingAnimation.hpp
//  Overworld
//
//  Created by Noah Kittleson on 6/3/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "GraphicsComponent.hpp"

enum class Direction {Up, Down, Left, Right, Stand};


class WalkingAnimation : public GraphicsComponent
{
public:
	WalkingAnimation(const sf::Texture& up, const sf::Texture& down,
					 const sf::Texture& left, const sf::Texture& right,
					 sf::Vector2f position, float timePerFrame);
	//virtual void update(MapObject& obj, float elapsed) override;
	void changeState(Direction newDir);
	
private:
	Direction walkingState;
	
	const sf::Texture* walkUp;
	const sf::Texture* walkDown;
	const sf::Texture* walkLeft;
	const sf::Texture* walkRight;
};

//nothing implemented for stand yet, but could be if that ever becomes a thing
