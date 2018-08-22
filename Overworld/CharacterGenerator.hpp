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

namespace Combatant {
	enum ID {
		Wheat,
		Logo,
		Pringus,
		Dingus,
		SittingSoldier
	};
}


class CharacterGenerator
{
public:
	static CharPtr create(const ResourceHolder& resources, Combatant::ID);
	
private:
	CharacterGenerator() {};

};
