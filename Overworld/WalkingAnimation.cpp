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
								   sf::Vector2f position, float timePerFrame, sf::Vector2i frame)
: AnimatedComponent(down, position, timePerFrame, frame), walkUp(&up), walkDown(&down), walkRight(&right), walkLeft(&left)
{
	//setOrigin(frame.x/2, frame.y/2);
	walkingState = Direction::Down;
}

void WalkingAnimation::changeDirection(Direction newDir) {
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
	stepTimer = 0;
}

Direction WalkingAnimation::getWalkingDirection()
{
	//this logic isn't going to work for any non-player sprite that walks...
	//use something more like input->movementVec
	sf::Vector2i moveVec;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		moveVec.y -= 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		moveVec.y += 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveVec.x -= 100;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveVec.x += 100;
	}
	
	Direction returnDir = Direction::Stand;
	if (moveVec.x > 0) {
		returnDir = Direction::Right;
	} else if (moveVec.x < 0) {
		returnDir = Direction::Left;
	} else if (moveVec.y < 0) {
		returnDir = Direction::Up;
	} else if (moveVec.y > 0) {
		returnDir = Direction::Down;
	}
	return returnDir;
}


void WalkingAnimation::update(float elapsed) {
	auto dir = getWalkingDirection();
	changeDirection(dir);
	
	if (walkingState != Direction::Stand) {
		totalElapsed += elapsed;
		if (totalElapsed > timePerFrame) {
			totalElapsed -= timePerFrame;
			nextFrame();
			if (++stepTimer > 4 && audio) {					//4 is a magic number
				audio->playSound(SoundID::shine);
				stepTimer = 0;
			}
		}
	}
}

std::unique_ptr<GraphicsComponent> WalkingAnimation::getCopy() {
	return std::unique_ptr<GraphicsComponent> (new WalkingAnimation (*this));
}

