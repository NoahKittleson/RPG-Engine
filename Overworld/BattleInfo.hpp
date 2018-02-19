//
//  BattleInfo.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/4/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "BattleAction.hpp"
#include "IterVector.hpp"

struct BattleInfo {
	IterVector<Character*> combatants;
	std::vector<Character*> NPCs;
	std::vector<Character*> PCs;
	BattleAction currentAction;
};
