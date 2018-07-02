//
//  PauseState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/29/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "PauseState.hpp"

PauseState::PauseState() {
	pausedText.setString("Paused");
	pausedText.setColor(sf::Color::White);
	pausedText.setPosition(100, 100);
	pausedText.setFont(resources.getFont(Fonts::Sansation));
}

void PauseState::update(sf::Clock& timer) {
	//nothing?
	timer.restart();
}

void PauseState::draw(sf::RenderWindow& rw) {
	rw.draw(pausedText);
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
