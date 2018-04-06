//
//  BattleEndMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/1/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BattleEndMode.hpp"

BattleEndMode::BattleEndMode(bool victory, const sf::Font& font)
: victory(victory)
{
	youDied.setFont(font);
	victory ? youDied.setString("You Defeated") : youDied.setString("You Died");
	youDied.setCharacterSize(100);
	youDied.setOrigin(youDied.getLocalBounds().width/2, youDied.getLocalBounds().height/2);
	youDied.setPosition(500, 350);										//these are cheating magic numbers
	youDied.setColor(sf::Color(255,255,255,100));
	
	screenFade.setSize(sf::Vector2f(1000,1000));
	screenFade.setPosition(0, 0);
	screenFade.setFillColor(sf::Color(0,0,0,0));
}

void BattleEndMode::update(float elapsed) {
	if (alpha < 255) {
		alpha += elapsed * 255;												//255 is a magic number
		screenFade.setFillColor(sf::Color(0,0,0,alpha));
	} else {
		alpha = 255;
		lingerTime -= elapsed;
		if (lingerTime < 0) {
			done = true;
		}
	}
}

void BattleEndMode::draw(sf::RenderWindow &rw) {
	rw.draw(screenFade);
	if (alpha < 150) {
		youDied.setPosition(500-(500*(150-alpha)/150), 350);			//chock full of magic numbers
		rw.draw(youDied);
		youDied.setPosition(500+(500*(150-alpha)/150), 350);			//chock full of magic numbers
		rw.draw(youDied);
	} else {
		youDied.setPosition(500, 350);									//these are cheating magic numbers
		rw.draw(youDied);
	}
}

void BattleEndMode::handleInput(sf::RenderWindow &rw) {
	return;
}
