//
//  AttackMode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "AttackMode.hpp"


AttackMode::AttackMode(BattleInfo& info) : info(info) {
	//right now the destination for each sprite is just 100 up from where it was originally
	originalPosMap.emplace(info.currentAction.attacker, info.currentAction.attacker->getSpritePosition());
	destinationMap.emplace(info.currentAction.attacker, info.currentAction.attacker->getSpritePosition() + sf::Vector2f(-100,0));
	for (auto & character : info.currentAction.defenders) {
		originalPosMap.emplace(character, character->getSpritePosition());
		destinationMap.emplace(character, character->getSpritePosition()+ sf::Vector2f(-100,0));	//100 is a magic number
	}
}

void AttackMode::update(float elapsed) {
	for (auto & item : destinationMap) {
		item.first->move(sf::Vector2f(item.second.x*2*elapsed, item.second.y*2*elapsed));			//2 is a magic number
		sf::Vector2f movementGap (item.second.x - originalPosMap[item.first].x,
								  item.second.y - originalPosMap[item.first].y);
	}
}

void AttackMode::draw(sf::RenderWindow &rw) {
	//set the proper views
	//draw all the sprites
}

void AttackMode::handleInput(sf::RenderWindow &rw) {
	sf::Event event;
	while (rw.pollEvent(event)) {
		return;
	}
}
