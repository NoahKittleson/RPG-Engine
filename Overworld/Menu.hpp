//
//  MenuContainer.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "IterVector.hpp"
#include "Character.h"
#include "Ability.hpp"

class MenuOption;
enum class Command {CursorUp, CursorDown, Select, Back};

class Menu {
public:
	void draw(sf::RenderWindow &rw);
	void update(float elapsed, std::vector<Command> commandVec);
	
	bool isActive() const {return active;};
	void activate();
	bool isDone() const;
	void addChild(std::shared_ptr<MenuOption>& item);
	
private:
	IterVector<std::shared_ptr<MenuOption>> children;
	bool active = false;
	static bool done;
};
