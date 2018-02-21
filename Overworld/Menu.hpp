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
#include "Ability.h"

class MenuItem;

class Menu {
public:
	
	void draw(sf::RenderWindow &rw);
	void update(float elapsed);
	void handleInput(sf::RenderWindow& rw);
	
	bool isActive() const {return active;};
	void addChild(std::string option, Menu* next);
	void addChild(std::shared_ptr<Character> option, Menu* next, std::function<void()>);
	void addChild(Ability& option, Menu* next, std::function<void()>);
	
private:
	IterVector<MenuItem> children;
	std::function<void()> callback;
	bool active = true;
};
