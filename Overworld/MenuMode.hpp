//
//  MenuMode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"
#include "Menu.hpp"
#include <stack>

class MenuMode: public Mode
{
public:
	MenuMode();
	virtual void update(float elapsed/*, combatants list?*/) override;		//all of these will just pass on to MenuNode.
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void handleInput(sf::RenderWindow &rw) override;
	
private:
	std::stack<Menu> menuSystem;
}
