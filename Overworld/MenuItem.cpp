//
//  MenuNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuItem.hpp"

MenuItem::MenuItem(MenuSubclass next) {
	nextMenu = next;
}


void MenuItem::activate() {
	if (active) {
		child->activate();
	} else {
		active = true;
		action.doIt();				//this is the missing piece
	}
}

void MenuItem::deactivate() {
	active = false;
}
void MenuItem::draw(sf::RenderWindow &rw) {
	rw.draw(text);
}
void MenuItem::update(float elapsed){
	//nothing?
}
void MenuItem::handleInput(sf::RenderWindow& rw) {
	if (/*select button pressed*/) {
		activate();
	}
	//also controls for moving around the container
	//I don't need handleInput if this isn't a menu item container?
}
void MenuItem::select() {
	text.setColor(selectColor);
}
void MenuItem::deselect() {
	text.setColor(defaultColor);
}
bool MenuItem::selectable() {
	return true;
	/// This one confuses me
}

