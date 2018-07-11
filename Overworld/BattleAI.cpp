//
//  BattleAI.cpp
//  Overworld
//
//  Created by Noah Kittleson on 7/11/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BattleAI.hpp"

void OpportunisticAI::FillAction(BattleInfo& info) {
	std::shared_ptr<Character> lowestHealthPC = info.PCs[0];
	for (auto & character : info.PCs) {
		if (lowestHealthPC->getHealth() == 0 || character->getHealth() < lowestHealthPC->getHealth()) {
			if (character->getHealth() != 0) {
				lowestHealthPC = character;
			}
		}
	}
}

