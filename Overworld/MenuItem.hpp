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
	MenuItem(std::string text, Menu* next, const sf::Font& font);
	MenuItem(std::string text, Menu* next, const sf::Font& font,  std::function<void()> callback);
	//MenuItem(MenuItem&& other);
	
	void draw(sf::RenderWindow& rw);
	void select();						//select is for highlighting current option, activate for executing it
	void activate();
	bool isActive() const;
	void deselect();
	bool isSelectable();
	Menu* getNext() const {return nextMenu;};
	void setSelect(bool selectable);
	
	bool isSelected() const {return selected;};
	void setPosition(int x, int y);
	std::string getName() {return text.getString();};

protected:
	sf::Text text;
	Menu* nextMenu = nullptr;
	std::function<void()> callback = []{return;};
	bool selected = false;
	bool possible = true;
	
	//define color Types across all MenuItems
	const sf::Color selectColor = sf::Color::Red;
	const sf::Color defaultColor = sf::Color::Black;
	const sf::Color unselectableColor = sf::Color(128,128,128);
};
