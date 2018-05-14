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
	auto attackOption = std::make_shared<MenuOption>("Attack", font, attackFunc);
	attackOption->attachNext(targetMenu);
	startMenu->addChild(attackOption);
	
	//set up Ability Option on Start Menu
	auto abilityOption = std::make_shared<MenuOption>("Ability", font);
	abilityOption->attachNext(abilityMenu);
	if (info.currentAction.attacker->getAbilityList().size() == 0) {
		abilityOption->setSelect(false);
	}
	startMenu->addChild(abilityOption);

	
	//set up Pass Option on Start Menu
	auto passOption = std::make_shared<MenuOption>("Pass", font);
	startMenu->addChild(passOption);
	
	//set up each option in Target Menu
	for (auto & target : info.combatants) {
		auto function = [&info, &target] () {
			info.currentAction.defenders.push_back(target);
		};
		auto targetOption = std::make_shared<MenuOption>(target->getName(), font, function);
		targetMenu->addChild(targetOption);
	}
	
	//set up each option in Ability Menu
	for (const auto & ability : info.currentAction.attacker->getAbilityList()) {
		auto function = [&info, &ability] () {
			info.currentAction.ability = &ability;
		};
		std::shared_ptr<MenuOption> addMe = std::make_shared<AbilityOption>(ability, font, info.combatants.get(), function);
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
