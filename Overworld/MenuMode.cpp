//
//  MenuMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MenuMode.hpp"

MenuMode::MenuMode() {
	//create starting menu Node
	Menu primary;
	Menu target;
	Menu ability;
	primary.addChild("Attack", &target);
	primary.addChild("Ability", &ability);
	primary.addChild("Pass", nullptr);
	
}

void MenuMode::update(float elapsed) {
	while (!menuSystem.top().isActive()) {
		menuSystem.pop();
		menuSystem.top();
	}
	menuSystem.top().update(elapsed);
}

void MenuMode::draw(sf::RenderWindow &rw) {
	menuSystem.top().draw(rw);
}

void MenuMode::handleInput(sf::RenderWindow &rw) {
	menuSystem.top().handleInput(rw);
}
