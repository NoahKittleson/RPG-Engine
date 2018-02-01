//
//  MenuMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuMode.hpp"

MenuMode::MenuMode() {
	//create starting menu Node
	MenuItem primary = MenuItem(MenuSubclass::Primary);
	MenuItem exampleAttack ("Attack", MenuSubclass::Ability, std::vector<Character*>(or pass this in when it needs to create child));
	
}

void MenuMode::update(float elapsed) {
	//menu update?
}
void MenuMode::draw(sf::RenderWindow &rw) {
	//draw
}
void MenuMode::handleInput(sf::RenderWindow &rw) {
	sf::Event event;
	while (rw.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::X:
					menu->activate();

				case sf::Keyboard::Up:
					menu->selectPrevious();
					break;
					
				case sf::Keyboard::Down:
					menu->selectNext();
					break;
					
				default:
					break;
			}
		}
	}
}
