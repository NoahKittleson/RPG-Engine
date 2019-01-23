//
//  MainMenuState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 10/29/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MainMenuState.hpp"

MainMenuState::MainMenuState()
: background(resources.getTexture(Textures::MainMenuBackground), sf::Vector2f(512, 384), 0.3, sf::Vector2i(256,192))	//magic number in position
{
	Title.setFont(resources.getFont(Fonts::Bramble));
	Title.setCharacterSize(150);
	Title.setColor(sf::Color(255,0,255));

	Title.setPosition(300, 70);
	Title.setString("Placeholder");
	
	background.setScale(4.0, 4.0);
	
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
	
//	background.setTexture(resources.getTexture(Textures::MainMenuBackground));
//	background.setScale(4, 4);

	mainMenu->activate();
}

void MainMenuState::update(sf::Clock& timer) {
	float elapsed = timer.restart().asSeconds();
	mainMenu->update(elapsed, this, commandVec);
	if (waxing) {
		colorTimer += elapsed;
		if (colorTimer > 3) {
			waxing = false;
		}
	} else {
		colorTimer -= elapsed;
		if (colorTimer < 0) {
			waxing = false;
		}
	}
	Title.setColor(sf::Color(255, elapsed * 40, 255));
	background.update(elapsed);
}

void MainMenuState::draw(sf::RenderWindow& rw) {
	rw.clear(sf::Color::White);
	rw.draw(background);
	rw.draw(Title);
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
