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

class MenuOption {
public:
	MenuOption(std::string text, const sf::Font& font, std::function<void()> callback = nullptr);
	
	virtual void draw(sf::RenderWindow& rw);
	virtual void select();						//select is for highlighting current option, activate for executing it
	virtual void activate();
	virtual bool isActive() const;
	virtual void deselect();
	virtual bool isSelectable();
	virtual std::shared_ptr<Menu> getNext() const { return nextMenu; };
	virtual void setSelect(bool selectable);
	
	void attachNext(std::shared_ptr<Menu> next) { nextMenu = next; };
	void setPosition(int x, int y);
	//std::string getName() const { return text.getString(); };
	bool isSelected() const { return selected; };

protected:
	sf::Text optionName;
	std::shared_ptr<Menu> nextMenu = nullptr;
	std::function<void()> callback = [] { return; };
	bool selected = false;
	bool possible = true;
	
	//define color Types across all MenuOptions
	const sf::Color selectColor = sf::Color::Red;
	const sf::Color defaultColor = sf::Color::Black;
	const sf::Color unselectableColor = sf::Color(128,128,128);
};


//things I need to accomplish that involve the orginal objects MenuOptions are supposed to be representing-
//-Draw Requirements and Description of Ability
//-Start TargetList on correct person (ally or enemy)
//-Put Select marker above selected character







