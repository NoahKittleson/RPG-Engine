//
//  InputComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/26/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "WalkingAnimation.hpp"

class InputComponent
{
public:
	virtual ~InputComponent() {}
	//InputComponent () {}
	virtual void update(sf::RenderWindow& rw, float elapsed);
	
private:

	
};
