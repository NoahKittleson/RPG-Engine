//
//  MenuNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuOption.hpp"

MenuOption::MenuOption(std::string t, Menu* next, const sf::Font& font) {
	nextMenu = next;
	text.setString(t);
	text.setFont(font);
	text.setColor(sf::Color::Black);

}

MenuOption::MenuOption(std::string t, Menu* next, const sf::Font& font, std::function<void()> callback) {
	nextMenu = next;
	text.setString(t);
	text.setFont(font);
	this->callback = callback;
	text.setColor(sf::Color::Black);
}

void MenuOption::draw(sf::RenderWindow& rw) {
	rw.draw(text);
}

void MenuOption::select() {
	text.setColor(selectColor);
}

void MenuOption::activate() {
	if (possible) {
		callback();
	}
}

void MenuOption::deselect() {
	if (possible) {
		text.setColor(defaultColor);
	} else {
		text.setColor(unselectableColor);
	}
}

bool MenuOption::isSelectable() {
	return possible;
}

void MenuOption::setPosition(int x, int y) {
	text.setPosition(x, y);
}

void MenuOption::setSelect(bool selectable) {
	possible = selectable;
	if (possible) {
		text.setColor(defaultColor);
	} else {
		text.setColor(unselectableColor);
	}
}



