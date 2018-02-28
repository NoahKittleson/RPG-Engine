//
//  PlayerObject.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "PlayerObject.hpp"

#define INTERACT_RANGE 10

PlayerObject::PlayerObject(graphicsPtr&& gc, RectVec& collision)
: MapObject(std::move(gc), collision, nullptr)
{
	
}

DNode* PlayerObject::interact(const MapSection& map) {
	//calculate bigger collision
	std::vector<sf::FloatRect> biggerCollision;
	for (auto const & box: collisionBoxes) {
		biggerCollision.emplace_back(box.left - INTERACT_RANGE,
									 box.top - INTERACT_RANGE,
									 box.width + INTERACT_RANGE * 2,
									 box.height + INTERACT_RANGE * 2);
	}
	
	return map.interact(biggerCollision);
}
