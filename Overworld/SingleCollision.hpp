//
//  Collision.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PhysicsComponent.cpp"

class SingleCollision : public PhysicsComponent
{
public:
    SingleCollision(sf::IntRect collisionBox);
	virtual bool intersects(sf::IntRect) const override;
	virtual void collide(Player&, sf::Vector2f movement) const override;
	
private:
    sf::IntRect collisionBox;
    
};
