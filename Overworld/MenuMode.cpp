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
	Menu primaryMenu;
	Menu targetMenu;
	Menu abilityMenu;
	primaryMenu.addChild("Attack", &targetMenu);
	primaryMenu.addChild("Ability", &abilityMenu);
	primaryMenu.addChild("Pass", nullptr);
	for (auto && target : characterList) {
		targetMenu.addChild(target);
	}
	for (auto && ability : currentChar.abilityList) {
		abilityMenu.addChild(ability);
	}
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
