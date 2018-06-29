//
//  PauseState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/29/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "PauseState.hpp"


void PauseState::update(sf::Clock&) {
	//nothing?
}

void PauseState::draw(sf::RenderWindow&) {
	//draw the pause menu
}

void PauseState::handleInput(sf::RenderWindow& rw) {
	sf::Event event;
	while (rw.pollEvent(event)) {
		//if P or Enter is pressed pop this state;
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
			requestStackPop();
		}
	}
}
