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
	pausedText.setFont(resources.getFont(Fonts::Bramble));
	rect.setFillColor(sf::Color::Black);
	rect.setSize(sf::Vector2f(105,37));
	rect.setPosition(90, 100);
	audioPlayer.pauseMusic();
	//pause sounds?
}

void PauseState::update(sf::Clock& timer) {
	//nothing?
	timer.restart();
}

void PauseState::draw(sf::RenderWindow& rw) {
//	rw.clear(sf::Color::Black);
	rw.setView(rw.getDefaultView());
	rw.draw(rect);
	rw.draw(pausedText);
	rw.display();
}

void PauseState::handleInput(sf::RenderWindow& rw) {
	sf::Event event;
	while (rw.pollEvent(event)) {
		//if P or Enter is pressed pop this state;
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
			requestStackPop();
			audioPlayer.resumeMusic();
		}
	}
}
