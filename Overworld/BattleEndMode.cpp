//
//  BattleEndMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/1/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BattleEndMode.hpp"

BattleEndMode::BattleEndMode() {
	screenFade.setSize(sf::Vector2f(1000,1000));
	screenFade.setPosition(0, 0);
	screenFade.setFillColor(sf::Color(0,0,0,0));
}

void BattleEndMode::update(float elapsed) {
	alpha += elapsed * 255;												//255 is a magic number
	screenFade.setFillColor(sf::Color(0,0,0,alpha));
	if (alpha > 255) {
		done = true;
	}
}

void BattleEndMode::draw(sf::RenderWindow &rw) {
	rw.draw(screenFade);
}

void BattleEndMode::handleInput(sf::RenderWindow &rw) {
	return;
}
