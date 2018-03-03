//
//  BattleAction.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/3/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BattleAction.hpp"

void BattleAction::clear() {
	attacker = nullptr;
	defenders.clear();
	ability = nullptr;
}

bool BattleAction::complete() const {
	if (ability && attacker && defenders.size()) {
		return true;
	} else return false;
}


