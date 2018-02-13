//
//  MenuNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuItem.hpp"

MenuItem::MenuItem(std::string t, Menu* next) {
	nextMenu = next;
	text.setString(t);
}

MenuItem::MenuItem(std::string t, Menu* next, std::function<void()> callback) {
	nextMenu = next;
	text.setString(t);
	this->callback = callback;
}

void MenuItem::draw(sf::RenderWindow& rw) {
	rw.draw(text);
}


void MenuItem::select() {
	text.setColor(selectColor);
}

void MenuItem::activate() {
	active = true;
}

void MenuItem::deselect() {
	text.setColor(defaultColor);
}

void MenuItem::deactivate() {
	active = false;
}

bool MenuItem::selectable() {
	return true;
	//only until I put in requirements
}
