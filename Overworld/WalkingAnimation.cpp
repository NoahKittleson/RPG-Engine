//
//  WalkingAnimation.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/3/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "WalkingAnimation.hpp"


WalkingAnimation::WalkingAnimation(const sf::Texture& up, const sf::Texture& down,
								   const sf::Texture& left, const sf::Texture& right,
								   sf::Vector2f position, float timePerFrame)
: GraphicsComponent(down, position), walkUp(&up), walkDown(&down), walkRight(&right), walkLeft(&left)
{
	//setOrigin(frame.x/2, frame.y/2);
}

void WalkingAnimation::changeState(Direction newDir) {
	if (walkingState == newDir) {
		return;
	}
	else switch (newDir) {
		case Direction::Up:
			setTexture(*walkUp);
			break;
			
		case Direction::Down:
			setTexture(*walkDown);
			break;
			
		case Direction::Left:
			setTexture(*walkLeft);
			break;
			
		case Direction::Right:
			setTexture(*walkRight);
			break;
			
		default:
			//right now this catches Stand.  Create case Stand if I add idle animation.
			break;
	}
	walkingState = newDir;
}
