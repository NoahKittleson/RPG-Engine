//
//  StatusEffect.hpp
//  Overworld
//
//  Created by Noah Kittleson on 3/19/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class StatusEffect
{
public:
	virtual void textify(sf::Text& text) = 0;
	
private:
	const std::string name;
	sf::Color displayColor;
};
