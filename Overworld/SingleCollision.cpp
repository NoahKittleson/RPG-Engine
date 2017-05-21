//
//  Collision.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "SingleCollision.hpp"

SingleCollision::SingleCollision(sf::IntRect collisionBox)
: collisionBox(collisionBox)
{
    
}

bool SingleCollision::intersects(sf::IntRect entity) const {
	return entity.intersects(collisionBox);
}

void SingleCollision::collide(Player& PC, sf::Vector2f movement) const {

	sf::IntRect playerRect = PC.getAbsBox();
	if (playerRect.intersects(collisionBox)) {
		if (movement.x == 0 && movement.y > 0) {			//moving down
			PC.setPosition(PC.getPosition().x,
						   collisionBox.top - playerRect.height/2);
		}
		else if (movement.x == 0 && movement.y < 0){		//moving up
			PC.setPosition(PC.getPosition().x,
						   collisionBox.top + collisionBox.height + playerRect.height/2);
		}
		else if (movement.x > 0 && movement.y == 0){		//moving right
			PC.setPosition(collisionBox.left - playerRect.width/2,
						   PC.getPosition().y);
		}
		else if (movement.x < 0 && movement.y == 0){		//moving left
			PC.setPosition(collisionBox.left + collisionBox.width + playerRect.width/2,
						   PC.getPosition().y);
		}
	}
}
