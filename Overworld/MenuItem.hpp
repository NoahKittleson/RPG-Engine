//
//  MenuNode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MenuNode.hpp"

class MenuItem {
public:
	enum MenuSubclass {Primary, Target, Ability, None};
	MenuItem(MenuSubclass next);
	
	void select();						//select is for highlighting current option, activate for executing it
	void activate();
	void deselect();
	void deactivate();
	bool selectable();
	
	bool isSelected() const {return selected;};
	
private:
	sf::Text text;
	MenuSubclass nextMenu = None;
	bool selected = false;
	bool active = false;
	
	//define color Types across all MenuItems
	const sf::Color selectColor = sf::Color::Red;
	const sf::Color defaultColor = sf::Color::Black;
	const sf::Color unselectableColor = sf::Color(128,128,128);
}
