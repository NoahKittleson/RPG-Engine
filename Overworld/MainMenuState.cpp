//
//  MainMenuState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 10/29/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MainMenuState.hpp"

MainMenuState::MainMenuState() {
	mainMenu = std::make_shared<Menu>();
//	std::shared_ptr<Menu> loadMenu = std::make_shared<Menu>();
//	std::shared_ptr<Menu> optionsMenu = std::make_shared<Menu>();

	//set up Ability Option on Start Menu
	auto abilityOption = std::make_shared<MenuOption>("Ability", font);
	abilityOption->attachNext(abilityMenu);
	if (info.currentAction.attacker->getAbilityList().size() == 0) {
		abilityOption->setPossible(false);
	}
	
	
	auto function = [this] () {
		requestStackAdd(std::unique_ptr<State>(new OverworldMode()));
	};
	auto targetOption = std::make_shared<MenuOption>(target->getName(), font, function);
	mainMenu->addChild(abilityOption);
	mainMenu->activate();
}

void MainMenuState::update(sf::Clock&) {
	
}

void MainMenuState::draw(sf::RenderWindow&) {
	
}

void MainMenuState::handleInput(sf::RenderWindow&) {
	
}
