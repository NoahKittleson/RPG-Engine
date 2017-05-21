//
//  PhysicsComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "MapObject.hpp"
#include "MapSection.h"

class PhysicsComponent {
public:
    virtual ~PhysicsComponent() {}
    PhysicsComponent();
    //virtual void update(MapObject& player, MapSection& map);	//I never use the Obj item called in.  Will I in the future?
	virtual bool intersects(sf::IntRect) const;
	virtual void collide(Player&, sf::Vector2f movement) const;
};
