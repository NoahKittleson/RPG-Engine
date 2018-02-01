//
//  MenuContainer.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Menu.hpp"


void Menu::draw(sf::RenderWindow &rw) {
	if (child->isActive()) {
		child->draw(rw);
	} else {
		//not doing this yet, but it'll just be drawing each member MenuNode
	}
}
void Menu::update(float elapsed) {
	if (child->isActive()) {
		child->update(elapsed);
	} else {
		//maybe some flicker on selected option?
		//continue animation
	}
}
void Menu::handleInput(sf::RenderWindow& rw) {
	if (child->isActive()) {
		child->handleInput(rw);
	} else {
		//up and down plus select
	}
}
