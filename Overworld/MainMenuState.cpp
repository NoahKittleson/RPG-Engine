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

	//New Game
	auto function = [this] () {
		requestStackAdd(std::unique_ptr<State>(new OverworldMode()));
	};
	auto newGameOption = std::make_shared<MenuOption>("New Game", resources.getFont(Fonts::Bramble), function);
	mainMenu->addChild(newGameOption);
	
	//Load
	auto emptyFunction = [this] () {
		return;
	};
	auto loadOption = std::make_shared<MenuOption>("Load", resources.getFont(Fonts::Bramble), emptyFunction);
	loadOption->setPossible(false);
	mainMenu->addChild(loadOption);

	//Options
//	auto emptyFunction = [this] () {
//		return;
//	};
	auto optionsOption = std::make_shared<MenuOption>("Options", resources.getFont(Fonts::Bramble), emptyFunction);
	optionsOption->setPossible(false);
	mainMenu->addChild(optionsOption);
	
	mainMenu->activate();
}

void MainMenuState::update(sf::Clock&) {
	
}

void MainMenuState::draw(sf::RenderWindow&) {
	
}

void MainMenuState::handleInput(sf::RenderWindow&) {
	
}
