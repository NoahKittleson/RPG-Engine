//
//  DManager.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "DialogueMode.h"

DialogueMode::DialogueMode(NodePtr start)
: currentDNode(start)
{
    start->setPosition(90, 768 * .74f);					//magic number
    currentDNode = start;
    currentDNode->clear();
	
	dialogueBar.setTexture(resources.getTexture(Textures::DialogueBar));
	dialogueBar.setScale(3, 3);								//should be scale
	dialogueBar.setPosition(50, 502);
}

void DialogueMode::handleInput(sf::RenderWindow& rw) {
	//handle all input
	sf::Event event;
	while (rw.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
			auto next = currentDNode->getNext(conditions);
			if (next == Dialogue::None) {
				currentDNode->resolveConditions(conditions);
				requestStackPop();
				return;
			}
			audioPlayer.playSound(SoundID::shine);
			if (next != currentDNode->getID()) {
				sf::Vector2f pos = currentDNode->getPosition();
				currentDNode->resolveConditions(conditions);
				currentDNode = DialogueFactory::create(next, resources);
				currentDNode->setPosition(pos);
			}
		}
		else currentDNode->handleInput(event);
	}
}

void DialogueMode::draw(sf::RenderWindow &rw) {
	rw.clear(sf::Color::White);
	sf::View mapView = rw.getView();
	currentMap->drawBackground(rw);
	currentMap->drawAllObjects(rw, *player);
	currentMap->drawLighting(rw);
	
	rw.setView(rw.getDefaultView());
	rw.draw(dialogueBar);
	currentDNode->draw(rw);
	
	rw.setView(mapView);
	rw.display();
}


void DialogueMode::update(sf::Clock &clock)
{
    float elapsed = clock.restart().asSeconds();
	currentDNode->update(elapsed, this->audioPlayer);
}
