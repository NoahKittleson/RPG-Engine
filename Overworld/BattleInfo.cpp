//
//  BattleInfo.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/4/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BattleInfo.hpp"


void BattleInfo::clear() {
	combatants.clear();
	NPCs.clear();
	PCs.clear();
	currentAction.clear();
}
