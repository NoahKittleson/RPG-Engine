//
//  CharacterGenerator.cpp
//  Overworld
//
//  Created by Noah Kittleson on 8/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "CharacterGenerator.hpp"


 CharPtr CharacterGenerator::create(const ResourceHolder& resources, Combatant::ID id)
{
	switch (id) {
		case Combatant::Logo:
			return CharPtr(new Character(100, 100, 10, resources.getTexture(Textures::Icon), resources.getFont(Fonts::Sansation), "Evil Logo", "Kill", true, resources.getTexture(Textures::Icon)));
			break;
			
		case Combatant::Wheat:
			return CharPtr(new Character(100, 100, 100,  resources.getTexture(Textures::RollingWheat), resources.getFont(Fonts::Sansation), "WheatMan", "Get 'em", true, resources.getTexture(Textures::RollingWheat)));
		
		default:
			std::cout << "Character ID not found.  Nothing created.\n";
			break;
	}
}
