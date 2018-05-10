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

class MenuItem;

class Menu {
public:
	
	void draw(sf::RenderWindow &rw);
	void update(float elapsed);
	void handleInput(sf::RenderWindow& rw);
	
	bool isActive() const {return active;};
	void activate();
	bool isDone() const;
	void addChild(MenuItem item);
	
private:
	IterVector<MenuItem> children;
	bool active = false;
	static bool done;
};
