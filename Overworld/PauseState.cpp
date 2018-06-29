//
//  PauseState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/29/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "PauseState.hpp"


void update(sf::Clock&) {
	//nothing?
}

void draw(sf::RenderWindow&) {
	//draw the pause menu
}

void handleInput(sf::RenderWindow& rw) {
	//
	sf::Event event;
	while (rw.pollEvent(event)) {
		//if P or Enter is pressed pop this state;
		if (event.KeyPressed == key.code.Enter) {
			requestStackPop();
		}
	}
}
