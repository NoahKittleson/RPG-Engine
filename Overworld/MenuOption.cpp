//
//  MenuNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuOption.hpp"

MenuOption::MenuOption(std::string text, const sf::Font& font, std::function<void()> callback) {
	optionName.setString(text);
	optionName.setFont(font);
	this->callback = callback;
	optionName.setColor(sf::Color::Black);
}

void MenuOption::draw(sf::RenderWindow& rw) {
	rw.draw(optionName);
}

void MenuOption::select() {
	optionName.setColor(selectColor);
}

void MenuOption::activate() {
	if (possible) {
		callback();
	}
	//if there's a nextMenu, activate that one now...
}

void MenuOption::deselect() {
	if (possible) {
		optionName.setColor(defaultColor);
	} else {
		optionName.setColor(unselectableColor);
	}
}

bool MenuOption::isSelectable() {
	return possible;
}

void MenuOption::setPosition(int x, int y) {
	optionName.setPosition(x, y);
}

void MenuOption::setSelect(bool selectable) {
	possible = selectable;
	if (possible) {
		optionName.setColor(defaultColor);
	} else {
		optionName.setColor(unselectableColor);
	}
}




