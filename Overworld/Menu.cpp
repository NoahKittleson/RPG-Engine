//
//  MenuContainer.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Menu.hpp"

void Menu::draw(sf::RenderWindow &rw) {
	if (children.get()->isActive()) {
		children.get()->draw(rw);
	} else {
		//not doing this yet, but it'll just be drawing each member MenuNode
	}
}
void Menu::update(float elapsed) {
	if (children->isActive()) {
		children->update(elapsed);
	} else {
		//maybe some flicker on selected option?
		//continue animation
	}
}
void Menu::handleInput(sf::RenderWindow& rw) {
	sf::Event event;
	while (rw.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::X:
					children.get()->activate();
					break;
					
				case sf::Keyboard::Z:
					active = false;
					break;
					
				case sf::Keyboard::Up:
					--children;
					break;
					
				case sf::Keyboard::Down:
					++children;
					break;
					
				default:
					break;
			}
		}
	}
}

void Menu::addChild(std::string option, Menu* next) {
	children.push_back(MenuItem(option, next));
}

void Menu::addChild(Character* option, Menu* next) {
	children.push_back(MenuItem(option->getName(), Menu* next));
}

void Menu::addChild(Ability& option, Menu* next) {
	children.push_back(MenuItem(option->getName(), Menu* next));
}

