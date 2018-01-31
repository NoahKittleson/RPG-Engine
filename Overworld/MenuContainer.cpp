//
//  MenuContainer.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuContainer.hpp"


void MenuContainer::draw(sf::RenderWindow &rw) {
	if (child->isActive()) {
		child->draw(rw);
	} else {
		//not doing this yet, but it'll just be drawing each member MenuNode
	}
}
void MenuContainer::update(float elapsed) {
	if (child->isActive()) {
		child->update(elapsed);
	} else {
		//maybe some flicker on selected option?
		//continue animation
	}
}
void MenuContainer::handleInput(sf::RenderWindow& rw) {
	if (child->isActive()) {
		child->handleInput(rw);
	} else {
		//up and down plus select
	}
}
void MenuContainer::select() {
	text.setColor(selectColor);
}
void MenuContainer::activate() {
	active = true;
	//make options.
}
void MenuContainer::deselect() {
	text.setColor(defaultColor);
}
void MenuContainer::deactivate() {
	
}
bool MenuContainer::selectable() {
	return false;
}
