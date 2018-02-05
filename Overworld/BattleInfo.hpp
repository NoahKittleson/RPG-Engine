//
//  BattleInfo.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/4/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "BattleAction.hpp"

struct BattleInfo {
	std::vector<Character*> combatants;
	BattleAction currentAction;
	std::vector<Character*>::iterator currentChar;
};
