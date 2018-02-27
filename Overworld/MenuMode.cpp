//
//  MenuMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuMode.hpp"

MenuMode::MenuMode(BattleInfo& info, const sf::Font& font) {
	//create starting menu Node
	Menu* primaryMenu = &menuStorage[0];
	Menu* targetMenu = &menuStorage[1];
	Menu* abilityMenu = &menuStorage[2];
	
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
	menuStorage[0].activate();
	//menuSystem should not be a thing.  Just go off of the original active/non-active system.  MenuItems don't have any way to add themselves to the MenuStack;
}

void MenuMode::update(float elapsed) {
//	while (!menuSystem.top().isActive()) {
//		menuSystem.pop();
//		menuSystem.top();
//	}
//	menuSystem.top().update(elapsed);
	menuStorage[0].update(elapsed);
	if (menuStorage[0].isDone()) {
		done = true;
	}
}

void MenuMode::draw(sf::RenderWindow &rw) {
//	menuSystem.top().draw(rw);
	menuStorage[0].draw(rw);
}

void MenuMode::handleInput(sf::RenderWindow &rw) {
//	assert(menuStorage.size() > 0);
	menuStorage[0].handleInput(rw);
//	menuSystem.top().handleInput(rw);
}