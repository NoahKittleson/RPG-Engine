//
//  CharacterGenerator.hpp
//  Overworld
//
//  Created by Noah Kittleson on 8/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//


#pragma once
#include "Character.h"
#include "ResourceHolder.h"

using CharPtr = std::shared_ptr<Character>;

namespace Characters {
	enum ID {
		Wheat,
		Logo
	};
}


class CharacterGenerator
{
public:
	static CharPtr create(const ResourceHolder& resources, Characters::ID);
	
private:
	CharacterGenerator() {};

};
