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
}

void MenuMode::update(float elapsed) {
	//menuTree update?
}
void MenuMode::draw(sf::RenderWindow &rw) {
	//draw
}
void MenuMode::handleInput(sf::RenderWindow &rw) {
	if (true/*select key pressed*/) {
		menu->activate();
	}
}
