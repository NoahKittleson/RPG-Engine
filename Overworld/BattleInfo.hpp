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

struct BattleInfo : sf::NonCopyable {
	IterVector<std::shared_ptr<Character>> combatants;
	std::vector<std::shared_ptr<Character>> NPCs;
	std::vector<std::shared_ptr<Character>> PCs;
	BattleAction currentAction;
};
