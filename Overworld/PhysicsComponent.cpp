//
//  PhysicsComponent.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "PhysicsComponent.hpp"


bool PhysicsComponent::intersects(sf::IntRect) const {
	return false;
}

void PhysicsComponent::handleCollisionX(MapObject &, float movement) const {
	return;
}

void PhysicsComponent::handleCollisionY(MapObject &, float movement) const {
	return;
}
