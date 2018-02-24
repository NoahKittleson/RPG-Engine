//
//  MenuMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuMode.hpp"

MenuMode::MenuMode(BattleInfo& info, sf::Font font) {
	//create starting menu Node
	Menu* primaryMenu = &menuStorage[1];
	Menu* targetMenu = &menuStorage[2];
	Menu* abilityMenu = &menuStorage[3];
	
	primaryMenu->addChild(MenuItem("Attack", targetMenu, font));
	primaryMenu->addChild(MenuItem("Ability", abilityMenu, font));
	primaryMenu->addChild(MenuItem("Pass", nullptr, font));
	
	
	for (auto & target : info.combatants) {
		auto function = [&info, &target] () {
			info.currentAction.defenders.push_back(target);
		};
		targetMenu->addChild(MenuItem(target->getName(), nullptr, font, function));
	}
	for (auto && ability : info.currentAction.attacker->_abilityList) {
		auto function = [&info, &ability] () {
			info.currentAction.ability = &ability;
		};
		abilityMenu->addChild(MenuItem(ability.getName(), targetMenu, font, function));
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
	assert(menuSystem.size() > 0);
	menuSystem.top().handleInput(rw);
}
