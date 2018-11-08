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

void MainMenuState::update(sf::Clock& timer) {
	mainMenu->update(timer.restart().asSeconds(), this, commandVec);
}

void MainMenuState::draw(sf::RenderWindow& rw) {
	rw.clear(sf::Color::White);
	//rw.draw(background);
	mainMenu->draw(rw);
	rw.display();
}

void MainMenuState::handleInput(sf::RenderWindow& rw) {
	//this code is exactly the same as that in BattleMode?  Perhaps find a way to extract it out and generalize it?
	
	commandVec.clear();
	sf::Event event;
	while (rw.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::X:
					commandVec.push_back(Command::Select);
					break;
					
				case sf::Keyboard::Z:
					commandVec.push_back(Command::Back);
					break;
					
				case sf::Keyboard::Up:
				case sf::Keyboard::Right:
					commandVec.push_back(Command::CursorUp);
					break;
					
				case sf::Keyboard::Down:
				case sf::Keyboard::Left:
					commandVec.push_back(Command::CursorDown);
					break;
					
				default:
					//std::cout << "Hey, don't press that key.  It doesn't do anything.\n";
					break;
			}
		}
	}
}
