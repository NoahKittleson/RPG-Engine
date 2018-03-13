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
	destinationMap.emplace(info.currentAction.attacker, info.currentAction.attacker->getSpritePosition() + sf::Vector2f(0,-100));																		//100 is a magic number
	for (auto & character : info.currentAction.defenders) {
		originalPosMap.emplace(character, character->getSpritePosition());
		destinationMap.emplace(character, character->getSpritePosition()+ sf::Vector2f(0,-100));	//100 is a magic number
	}
}

void AttackMode::update(float elapsed) {
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
			
		default:
			std::cout << "Somthing is wrong.  Incorrect phase";
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
			currentPhase = animate;
		}
	}
}

void AttackMode::animateUpdate(float elapsed) {
//	static bool attackStarted (false);
//	static bool getHitStarted (false);
//	static float totalElapsed (0);
//	totalElapsed += elapsed;
//	if (!attackStarted) {
//		if (info.currentAction.ability->hitAnimation != nullptr) {
//			info.currentAction.attacker->setAnimation(*info.currentAction.ability->hitAnimation);
//		} else {
//			std::cout << "FUCC\n";
//		}
//		attackStarted = true;
//	}
//	info.currentAction.attacker->animate(elapsed);
//	bool allDone = info.currentAction.attacker->isIdle();
//	if (!getHitStarted && (totalElapsed > info.currentAction.ability->hitsOnFrame * 0.1)) {		//magic number 0.1
//		for (auto & it : info.currentAction.defenders) {
//			it->startGetHitAnimation();
//		}
//		getHitStarted = true;
//	}
//	info.currentAction.attacker->animate(elapsed);
//	for (auto & it : info.currentAction.defenders) {
//		it->animate(elapsed);
//		allDone = allDone && it->isIdle();
//	}
//	if (attackStarted && getHitStarted && allDone) {
//		currentPhase = moveBack;
//		attackStarted = false;
//		getHitStarted = false;
//		totalElapsed = 0;
//	}
	currentPhase = moveBack;
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
