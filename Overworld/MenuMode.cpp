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
	while (!menuSystem.back().isActive()) {
		menuSystem.pop_back();
	}
	menuSystem.back().update(elapsed);
}

void MenuMode::draw(sf::RenderWindow &rw) {
	menuSystem.back().draw(rw);
}

void MenuMode::handleInput(sf::RenderWindow &rw) {
	menuSystem.back().handleInput(rw);
}
