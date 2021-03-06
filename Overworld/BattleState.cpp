//
//  BattleState.cpp
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "BattleState.h"

BattleState::BattleState(std::vector<std::shared_ptr<Character>>& enemies) {
    for (auto && it : party) {
		it->attachAudio(audioPlayer);
        info.combatants.push_back(it);
    }
    for (auto && it : enemies) {
		it->attachAudio(audioPlayer);
		info.combatants.emplace_back(it);
    }
	while (info.combatants.get()->getHealth() <= 0) {
		++info.combatants;
	}
	info.currentAction.attacker = info.combatants.get();

	info.NPCs = enemies;
	info.PCs = party;
	phase = make_unique<MenuMode>(info, resources.getFont(Fonts::Bramble));
	
    info.combatants.setLooping(true);
	positionSpritesAndStats();
}

void BattleState::update(sf::Clock& timer) {
    float elapsed = timer.restart().asSeconds();
	if (phase) {
		phase->update(elapsed, this);
	}
	//updateSprites(elapsed);
	if (phase->isDone()) {
		switch (currentMode) {
			case menu:
				phase = make_unique<AttackMode>(info);
				currentMode = attack;
				std::cout << "Mode changed to attack.\n";
				break;
				
			case attack:
				if (checkBattleOver()) {		//positioning it here might make dying by poison on last guy wonky
					break;
				} else {
				do {
					++info.combatants;
				} while (info.combatants.get()->getHealth() <= 0);
				info.currentAction.clear();
				info.currentAction.attacker = info.combatants.get();
				phase = make_unique<MenuMode>(info, resources.getFont(Fonts::Bramble));
				currentMode = menu;
				std::cout << "Mode changed to menu.\n";
				break;
				}
				
			case victory:
			case defeat:
				requestStackPop();
				break;
				
			default:
				std::cout << "Mode unaccounted for.\n";
				break;
		}
	}
}

void BattleState::draw(sf::RenderWindow& rw) {
	rw.setView(rw.getDefaultView());
	rw.clear(sf::Color::White);
	drawAll(rw);
	if (phase) {
		phase->draw(rw);
	} else {
		//anything?
	}
    rw.display();
}

void BattleState::handleInput(sf::RenderWindow& rw) {
	if (phase) {
		phase->handleInput(rw);
	} else {
		sf::Event event;
		while (rw.pollEvent(event)) {
			//nothing
		}
	}
}

void BattleState::drawAll(sf::RenderWindow &rw) {
	int fuck = 0;
	for (auto && it: info.combatants) {
		it->drawAllStats(rw);
		it->drawSprite(rw);
		++fuck;
	}
}

void BattleState::positionSpritesAndStats() {
	sf::Vector2f windowSize (1024, 768);											//1024, 768 is a magic number
	float xSpacing = windowSize.x/(info.combatants.size()+1);						//the +1 is for padding on either side
	float ySpacing = 70;															//70 is a magic number
	sf::Vector2f position(xSpacing, windowSize.y*3/4);								//*3/4 semi-magic?
	for (char iii = 0; iii < info.combatants.size(); ++iii) {
		info.combatants[iii]->setStatPosition(position.x + xSpacing * iii, position.y);
		info.combatants[iii]->setSpritePosition(position.x + xSpacing * iii, position.y - ySpacing);
	}
}

bool BattleState::checkBattleOver() {
	bool playersDead = true;
	bool enemiesDead = true;
	for (auto const & character : info.combatants) {
		if (character->isNPC()) {
			enemiesDead = character->isIncapped() && enemiesDead;
		} else {
			playersDead = character->isIncapped() && playersDead;
		}
	}
	if (playersDead) {
		currentMode = defeat;
		phase = make_unique<BattleEndMode>(false, resources.getFont(Fonts::Bramble));
		return true;
	} else if (enemiesDead) {
		currentMode = victory;
		phase = make_unique<BattleEndMode>(true, resources.getFont(Fonts::Bramble));
		return true;
	}
	return false;
}






