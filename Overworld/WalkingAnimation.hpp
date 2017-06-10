//
//  WalkingAnimation.hpp
//  Overworld
//
//  Created by Noah Kittleson on 6/3/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "AnimatedComponent.hpp"

enum class Direction {Up, Down, Left, Right, Stand};


class WalkingAnimation : public AnimatedComponent
{
public:
	WalkingAnimation(const sf::Texture& up, const sf::Texture& down,
					 const sf::Texture& left, const sf::Texture& right,
					 sf::Vector2f position, float timePerFrame, sf::Vector2i frame);
	//virtual void update(MapObject& obj, float elapsed) override;
	void changeState(Direction newDir);
	void changeState(bool moving);
	void update(MapObject& obj, float elapsed) override;
	
private:
	Direction walkingState;
	bool moving;
	
	const sf::Texture* walkUp;
	const sf::Texture* walkDown;
	const sf::Texture* walkLeft;
	const sf::Texture* walkRight;
};

//nothing implemented for stand yet, but could be if that ever becomes a thing
