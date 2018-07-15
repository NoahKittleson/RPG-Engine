//
//  DManager.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "DialogueMode.h"

DialogueMode::DialogueMode(NodePtr start, const sf::RenderWindow &rw)
: currentDNode(start), mapView(rw.getView()), HUD(rw.getDefaultView())
{
    start->setPosition(90, HUD.getSize().y * .74f);
    currentDNode = start;
    currentDNode->clear();
    messageBox.setPosition(70, HUD.getSize().y * .7f);
    messageBox.setSize(sf::Vector2f(HUD.getSize().x, HUD.getSize().y/4));
    messageBox.setFillColor(sf::Color(153,76,0));
	
	dialogueBar.setTexture(resources.getTexture(Textures::DialogueBar));
	dialogueBar.setScale(3, 3);			//should be scale
	dialogueBar.setPosition(50, 550);
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
			} if (next != currentDNode->getID()) {
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
	rw.setView(mapView);
	currentMap->drawBackground(rw);
	currentMap->drawAllObjects(rw, *player);
	rw.setView(HUD);
	
//	rw.draw(messageBox);
	rw.draw(dialogueBar);
	
	currentDNode->draw(rw);
	rw.display();
}


void DialogueMode::update(sf::Clock &clock)
{
    float elapsed = clock.restart().asSeconds();
	currentDNode->update(elapsed);
}
