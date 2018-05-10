//
//  MenuMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuMode.hpp"

MenuMode::MenuMode(BattleInfo& info, const sf::Font& font) : info(info)
{
	//startMenu has already been created...
	std::shared_ptr<Menu> abilityMenu;
	std::shared_ptr<Menu> targetMenu;

	//set up Attack Option on Start Menu
	const Ability& autoAttack = info.currentAction.attacker->getBasicAttack();
	auto attackFunc = [&info, &autoAttack] () {
		info.currentAction.ability = &autoAttack;
	};
	MenuOption attackOption ("Attack", font, attackFunc);
	attackOption.attachNext(targetMenu);
	startMenu->addChild(attackOption);
	
	//set up Ability Option on Start Menu
	MenuOption abilityOption ("Ability", font);
	abilityOption.attachNext(abilityMenu);
	if (info.currentAction.attacker->getAbilityList().size() == 0) {
		abilityOption.setSelect(false);
	}
	
	//set up Pass Option on Start Menu
	MenuOption passOption ("Attack", font, attackFunc);
	startMenu->addChild(passOption);
	
	//set up each option on Target Menu
	for (auto & target : info.combatants) {
		auto function = [&info, &target] () {
			info.currentAction.defenders.push_back(target);
		};
		targetMenu->addChild(MenuOption(target->getName(), nullptr, font, function));
	}
	int iii = 0;
	for (const auto & ability : info.currentAction.attacker->getAbilityList()) {
		auto function = [&info, &ability] () {
			info.currentAction.ability = &ability;
		};
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
