//
//  MenuMode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include <stack>
#include "Mode.hpp"
#include "MenuItem.hpp"
#include "Menu.hpp"
#include "BattleInfo.hpp"

class MenuMode: public Mode
{
public:
	MenuMode();
	virtual void update(float elapsed, BattleInfo& info) override;		//all of these will just pass on to MenuNode.
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void handleInput(sf::RenderWindow &rw) override;
	
private:
	std::stack<Menu> menuSystem;
};


class Battle
{
public:
	//list of combatants
	//current turn marker?
	
private:
	
};
