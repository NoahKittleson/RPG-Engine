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
	int center = 512; 	///the most magic number in the world
	
	originalPosMap.emplace(info.currentAction.attacker, info.currentAction.attacker->getSpritePosition());
	destinationMap.emplace(info.currentAction.attacker, sf::Vector2f(center-50, info.currentAction.attacker->getSpritePosition().y-100));														//100 is a magic number
	for (auto & character : info.currentAction.defenders) {
		originalPosMap.emplace(character, character->getSpritePosition());
		destinationMap.emplace(character, sf::Vector2f(center, character->getSpritePosition().y-100));	//100 is a magic number
		center += 50;
	}
}

void AttackMode::update(float elapsed, State* context) {
	switch (currentPhase) {
		case moveTo:
			moveToUpdate(elapsed);
			break;
			
		case animate:
			animateUpdate(elapsed);
			break;
			
		case moveBack:
			moveBackUpdate(elapsed);
			break;
			
		case applyDamage:
			for (auto & defender : info.currentAction.defenders) {
				defender->calculateDmg(*info.currentAction.ability, info.currentAction.attacker);
			}
			currentPhase = animate;
			break;
			
		default:
			std::cout << "Somthing is wrong.  Incorrect phase\n";
			break;
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

void AttackMode::moveToUpdate(float elapsed) {
	for (auto & item : destinationMap) {
		sf::Vector2f movementGap (item.second.x - originalPosMap[item.first].x,
								  item.second.y - originalPosMap[item.first].y);
		item.first->move(sf::Vector2f(movementGap.x*2*elapsed, movementGap.y*2*elapsed));			//2 is a magic number
		sf::Vector2f distanceMoved (item.first->getSpritePosition().x - originalPosMap[item.first].x,
									item.first->getSpritePosition().y - originalPosMap[item.first].y);
		if (abs(distanceMoved.x) > abs(movementGap.x) || abs(distanceMoved.y) > abs(movementGap.y)) {
			item.first->setSpritePosition(item.second.x, item.second.y);
			currentPhase = applyDamage;
		}
	}
}

void AttackMode::animateUpdate(float elapsed) {
	static bool getHitStarted (false);
	static float totalElapsed (0);
	bool allDone = info.currentAction.attacker->isIdle();

	if (!getHitStarted && (totalElapsed > info.currentAction.ability->hitsOnFrame * 0.1)) {		//magic number 0.1
		for (auto & it : info.currentAction.defenders) {
			it->startGetHitAnimation();
		}
		getHitStarted = true;
	}
	info.currentAction.attacker->animate(elapsed);
	for (auto & it : info.currentAction.defenders) {
		it->animate(elapsed);
		allDone = allDone && it->isIdle();
	}
	if (allDone) {
		currentPhase = moveBack;
		totalElapsed = 0;
		getHitStarted = false;
	}
	totalElapsed += elapsed;
}

void AttackMode::moveBackUpdate(float elapsed) {
	for (auto & item : originalPosMap) {
		sf::Vector2f movementGap (item.second.x - destinationMap[item.first].x,
								  item.second.y - destinationMap[item.first].y);
		item.first->move(sf::Vector2f(movementGap.x*2*elapsed, movementGap.y*2*elapsed));			//2 is a magic number
		sf::Vector2f distanceMoved (item.first->getSpritePosition().x - destinationMap[item.first].x,
									item.first->getSpritePosition().y - destinationMap[item.first].y);
		if (abs(distanceMoved.x) > abs(movementGap.x) || abs(distanceMoved.y) > abs(movementGap.y)) {
			item.first->setSpritePosition(item.second.x, item.second.y);
			done = true;
		}
	}
}
