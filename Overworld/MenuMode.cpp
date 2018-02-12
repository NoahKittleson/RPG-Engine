//
//  MenuMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuMode.hpp"

MenuMode::MenuMode(BattleInfo& info) {
	//create starting menu Node
	Menu primaryMenu;
	Menu targetMenu;
	Menu abilityMenu;
	//THESE ONLY LIVE IN THIS SCOPE^^^^^
	
	primaryMenu.addChild("Attack", &targetMenu);
	primaryMenu.addChild("Ability", &abilityMenu);
	primaryMenu.addChild("Pass", nullptr);
	
	for (auto && target : info.combatants) {
		auto function = [info, target] () {
			info.currentAction.defenders.push_back(&target);
		};
		targetMenu.addChild(target, nullptr, function);
	}
	for (auto && ability : info.currentAction.attacker->_abilityList) {
		auto function = [info, ability] () {
			info.currentAction.ability = &ability;
		};
		abilityMenu.addChild(ability, &targetMenu, function);
	}
}

void MenuMode::update(float elapsed) {
	while (!menuSystem.top().isActive()) {
		menuSystem.pop();
		menuSystem.top();
	}
	menuSystem.top().update(elapsed);
}

void MenuMode::draw(sf::RenderWindow &rw) {
	menuSystem.top().draw(rw);
}

void MenuMode::handleInput(sf::RenderWindow &rw) {
	menuSystem.top().handleInput(rw);
}
