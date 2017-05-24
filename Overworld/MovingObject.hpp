//
//  MovingObject.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/23/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "MapObject.hpp"

class MovingObject : public MapObject
{
public:
	MovingObject() {}
	sf::IntRect getAbsBox() const;
	
private:
	
	
};
