//
//  MenuNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuItem.hpp"

MenuItem::MenuItem(std::string t, Menu* next, const sf::Font& font) {
	nextMenu = next;
	text.setString(t);
	text.setFont(font);
	text.setColor(sf::Color::Black);

}

MenuItem::MenuItem(std::string t, Menu* next, const sf::Font& font, std::function<void()> callback) {
	nextMenu = next;
	text.setString(t);
	text.setFont(font);
	this->callback = callback;
	text.setColor(sf::Color::Black);
}

void MenuItem::draw(sf::RenderWindow& rw) {
	rw.draw(text);
}

void MenuItem::select() {
	text.setColor(selectColor);
}

void MenuItem::activate() {
	if (possible) {
		callback();
	}
}

void MenuItem::deselect() {
	if (possible) {
		text.setColor(defaultColor);
	} else {
		text.setColor(unselectableColor);
	}
}

bool MenuItem::isSelectable() {
	return possible;
}

void MenuItem::setPosition(int x, int y) {
	text.setPosition(x, y);
}

void MenuItem::setSelect(bool selectable) {
	possible = selectable;
	if (possible) {
		text.setColor(defaultColor);
	} else {
		text.setColor(unselectableColor);
	}
}



