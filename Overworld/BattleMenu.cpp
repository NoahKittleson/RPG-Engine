//
//  BattleMenu.cpp
//  SFML test
//
//  Created by Noah Kittleson on 1/12/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleMenu.h"

void BattleMenu::update(float elapsed) {
	//for every combatant-
	for (auto & it : battleState.combatants) {
		it.animate(elapsed);
	}
}

void BattleMenu::draw(sf::RenderWindow &rw) {
	//draw all menu items
	if(!action.attacker) {
		//draw base menu
	} else if(!action.ability) {
		//draw ability menu
	} else if (action.defenders.empty()) {
		//draw targetting menu
	} else {
		//this menu is done!
	}
	
	//draw stats
	//draw descriptions (if necessary)
	//don't bother drawing sprites, they will be drawn in main branch
}

void BattleMenu::handleInput(sf::RenderWindow &rw) {
	if(!action.attacker) {
		//run base menu
	} else if(!action.ability) {
		//run ability menu
	} else if (action.defenders.empty()) {
		//run targetting menu
	}
	
	
	//determine what the active menu is (how?)
	//scroll up/down
	//read 'select's and process them
	
	//find a way to change modes and communicate info to new mode when menu action is selected...
}
