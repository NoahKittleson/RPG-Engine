//
//  MenuContainer.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "IterVector.hpp"

class MenuItem;

class Menu {
public:
	
	void draw(sf::RenderWindow &rw);
	void update(float elapsed);
	void handleInput(sf::RenderWindow& rw);
	
	bool isActive() const {return active;};
	void addChild(std::string option, Menu* next);
	
private:
	IterVector<MenuItem> children;
	bool active = true;
};
