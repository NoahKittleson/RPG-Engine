//
//  MenuNode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class Menu;

class MenuItem {
public:
	MenuItem(std::string text, Menu* next);
	MenuItem(std::string text, Menu* next, std::function<void()> callback);
	
	void draw(sf::RenderWindow& rw);
	void select();						//select is for highlighting current option, activate for executing it
	void activate();
	void deselect();
	void deactivate();
	bool selectable();
	
	bool isSelected() const {return selected;};
	
private:
	sf::Text text;
	Menu* nextMenu = nullptr;
	std::function<void()> callback;
	bool selected = false;
	bool active = false;
	
	//define color Types across all MenuItems
	const sf::Color selectColor = sf::Color::Red;
	const sf::Color defaultColor = sf::Color::Black;
	const sf::Color unselectableColor = sf::Color(128,128,128);
};
