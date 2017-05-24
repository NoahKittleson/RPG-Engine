//
//  Collision.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PhysicsComponent.hpp"

class SingleCollision : public PhysicsComponent
{
public:
    SingleCollision(sf::IntRect collisionBox);
	virtual bool intersects(sf::IntRect) const override;
	virtual bool intersects(PhysicsComponent*) const override;
	virtual void handleCollisionX(MapObject&, float movement) const override;
	virtual void handleCollisionY(MapObject&, float movement) const override;

	
private:
    sf::IntRect collisionBox;
	
};

//for multiple collision boxes-
//for (auto && box : boxlist) {
//	if (physics->intersects(box)) {
//		//collide boxes
//	}
//}
