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
	startMenu = std::make_shared<Menu>();
	std::shared_ptr<Menu> abilityMenu = std::make_shared<Menu>();
	std::shared_ptr<Menu> targetMenu = std::make_shared<Menu>();

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
	startMenu->addChild(abilityOption);

	
	//set up Pass Option on Start Menu
	MenuOption passOption ("Pass", font, attackFunc);
	startMenu->addChild(passOption);
	
	//set up each option in Target Menu
	for (auto & target : info.combatants) {
		auto function = [&info, &target] () {
			info.currentAction.defenders.push_back(target);
		};
		MenuOption targetOption (target->getName(), font, function);
		//targetOption.attachNext(nullptr);
		targetMenu->addChild(targetOption);
	}
	
	//set up each option in Ability Menu
	for (const auto & ability : info.currentAction.attacker->getAbilityList()) {
		auto function = [&info, &ability] () {
			info.currentAction.ability = &ability;
		};
		AbilityOption addMe (ability, font, info.combatants.get(), function);
		abilityMenu->addChild(addMe);
	}
	startMenu->activate();
}

void MenuMode::update(float elapsed) {
	startMenu->update(elapsed);
	if (info.currentAction.complete()) {
		done = true;
	}
	for (const auto & it : info.combatants) {
		it->animate(elapsed);
	}
}

void MenuMode::draw(sf::RenderWindow &rw) {
	startMenu->draw(rw);
}

void MenuMode::handleInput(sf::RenderWindow &rw) {
	startMenu->handleInput(rw);
}
