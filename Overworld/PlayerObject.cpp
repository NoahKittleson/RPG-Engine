//
//  PlayerObject.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "PlayerObject.hpp"

#define INTERACT_RANGE 10

PlayerObject::PlayerObject(GraphicsComponent* gc, RectVec& collision)
: MapObject(gc, collision, nullptr)
{
	
}

DNode* PlayerObject::interact(MapSection *map) {
	//calculate bigger collision
	std::vector<sf::FloatRect> biggerCollision;
	for (auto const & box: collisionBoxes) {
		biggerCollision.emplace_back(box.left - INTERACT_RANGE,
												box.top - INTERACT_RANGE,
												box.width + INTERACT_RANGE * 2,
												box.height + INTERACT_RANGE * 2);
	}
	
	//see if I intersect any other sprites with bigger collision
	for (auto && sprite: map->getSpriteList()) {
		for (auto && box: biggerCollision) {
			if (sprite.intersects(box)) {
				//return corresponding ptr if DNode is not nullptr
				auto ptr = sprite.getDNode();
				if (ptr != nullptr) {
					return ptr;
				}
			}
		}
	}
	return nullptr;
}
