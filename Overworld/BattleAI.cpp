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
	info.currentAction.defenders.push_back(lowestHealthPC);
	info.currentAction.ability = &info.currentAction.attacker->getBasicAttack();
}

void RandomAI::FillAction(BattleInfo &info) {
	//get random ability
	if (info.currentAction.attacker->getAbilityList().size()) {
		int randomNumber = std::rand() % info.currentAction.attacker->getAbilityList().size();
		info.currentAction.ability = &info.currentAction.attacker->getAbilityList()[randomNumber];
	} else {
		info.currentAction.ability = &info.currentAction.attacker->getBasicAttack();
	}
	
	//get random defender
	int randomNumber = std::rand() % info.PCs.size();
	info.currentAction.defenders.push_back(info.PCs[randomNumber]);
}

