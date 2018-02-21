//
//  BattleAction.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/3/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "Character.h"
#include "Ability.h"

//^Is this going to cause a circular dependency?

struct BattleAction {	
	std::shared_ptr<Character> attacker = nullptr;
	std::vector<std::shared_ptr<Character>> defenders;
	Ability* ability = nullptr;
};
