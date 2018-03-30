//
//  MenuMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuMode.hpp"

MenuMode::MenuMode(BattleInfo& info, const sf::Font& font) : info(info) {
	//create starting menu Node
	Menu* primaryMenu = &menuStorage[0];
	Menu* targetMenu = &menuStorage[1];
	Menu* abilityMenu = &menuStorage[2];
	
	const Ability& autoAttack = info.currentAction.attacker->getBasicAttack();
	auto attackFunc = [&info, &autoAttack] () {
		info.currentAction.ability = &autoAttack;
		std::cout << "Ability set: " << autoAttack.getName() << "\n";
	};
	
	primaryMenu->addChild(MenuItem("Attack", targetMenu, font, attackFunc));
	MenuItem abilityOption ("Ability", abilityMenu, font);
	if (info.currentAction.attacker->getAbilityList().size() == 0) {
		abilityOption.setSelect(false);
	}
	primaryMenu->addChild(abilityOption);
	primaryMenu->addChild(MenuItem("Pass", nullptr, font));
	
	
	for (auto & target : info.combatants) {
		auto function = [&info, &target] () {
			info.currentAction.defenders.push_back(target);
		};
		targetMenu->addChild(MenuItem(target->getName(), nullptr, font, function));
	}
	int iii = 0;
	for (const auto & ability : info.currentAction.attacker->getAbilityList()) {
		auto function = [&info, &ability] () {
			info.currentAction.ability = &ability;
		};
		std::cout << "Ability set: " << ability.getName() << "\n";
		std::cout << "ABILITY ADDRESS:" << &ability << "\n";
		std::cout << "Ability should be: " << info.currentAction.attacker->getAbilityList()[0].getName() << "\n";
		std::cout << "ABILITY ADDRESS should be: " << &info.currentAction.attacker->getAbilityList()[0] << "\n";

		MenuItem addMe (ability.getName(), targetMenu, font, function);
		if (info.combatants.get()->checkAbilityCost(ability)) {
			addMe.setSelect(true);
		}
		abilityMenu->addChild(addMe);
		iii++;
	}
	menuStorage[0].activate();
}

void MenuMode::update(float elapsed) {
	menuStorage[0].update(elapsed);
	if (info.currentAction.complete()) {
		done = true;
	}
	for (const auto & it : info.combatants) {
		it->animate(elapsed);
	}
}

void MenuMode::draw(sf::RenderWindow &rw) {
	menuStorage[0].draw(rw);
}

void MenuMode::handleInput(sf::RenderWindow &rw) {
	menuStorage[0].handleInput(rw);
}
