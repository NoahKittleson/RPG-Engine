//
//  BattleAction.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/3/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
//#include "Character.h"
#include "Ability.hpp"

//^Is this going to cause a circular dependency? YES

class Character;

struct BattleAction {	
	std::shared_ptr<Character> attacker = nullptr;
	std::vector<std::shared_ptr<Character>> defenders;
	const Ability* ability = nullptr;
	
	void clear();
	bool complete() const;
	//void carryOutAction() 		//might be nice to have this here.
};

#pragma once
#include "Character.h"			//putting this down here avoids a circular dependency issue
