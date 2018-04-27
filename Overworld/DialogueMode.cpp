//
//  DManager.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "DialogueMode.h"

DialogueMode::DialogueMode(DNode* start, const sf::RenderWindow &rw)
: currentDNode(start), mapView(rw.getView()), HUD(rw.getDefaultView())
{
    start->setPosition(0, HUD.getSize().y * .75f);
    currentDNode = start;
    currentDNode->clear();
    messageBox.setPosition(0, HUD.getSize().y * .75f);
    messageBox.setSize(sf::Vector2f(HUD.getSize().x, HUD.getSize().y/4));
    messageBox.setFillColor(sf::Color(153,76,0));
}

void DialogueMode::handleInput(sf::RenderWindow& rw) {
	//handle all input
	sf::Event event;
	while (rw.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
			currentDNode->resolveConditions(conditions);
			auto next = currentDNode->getNext();
			if (next != Dialogue::None) {
				currentDNode = DialogueFactory::create(next, resources);
			} else {
				requestStackPop();
				return;
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
	rw.draw(messageBox);
	currentDNode->draw(rw);
	rw.display();
}


void DialogueMode::update(sf::Clock &clock)
{
    float elapsed = clock.restart().asSeconds();
	currentDNode->update(elapsed);
}
