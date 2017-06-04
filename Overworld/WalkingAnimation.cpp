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
	
}

void WalkingAnimation::changeState(Direction newDir) {
	if (walkingState == newDir) {
		return;
	}
	else switch (newDir) {
		case Up:
			setTexture(*walkUp);
			break;
			
		case Down:
			setTexture(*walkDown);
			break;
			
		case Left:
			setTexture(*walkLeft);
			break;
			
		case Right:
			setTexture(*walkRight);
			break;
			
		default:
			//right now this catches Stand.  Create case Stand if I add idle animation.
			break;
	}
	walkingState = newDir;
}
