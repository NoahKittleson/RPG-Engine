//
//  Collision.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PhysicsComponent.cpp"

class Collision : public PhysicsComponent
{
public:
    Collision(sf::IntRect collisionBox);
    virtual void update(MapObject& obj, MapSection& map) override;
    
private:
    sf::IntRect collisionBox;
    
};
