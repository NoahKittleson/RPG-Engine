//
//  DManager.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "DialogueMode.h"

DialogueMode::DialogueMode(DNode* start, const sf::RenderWindow &rw)
: current(start), mapView(rw.getView()), HUD(rw.getDefaultView())
{
    start->setPosition(0, HUD.getSize().y * .75f);
    current = start;
    current->clear();
    messageBox.setPosition(0, HUD.getSize().y * .75f);
    messageBox.setSize(sf::Vector2f(HUD.getSize().x, HUD.getSize().y/4));
    messageBox.setFillColor(sf::Color(153,76,0));
}

std::string DialogueMode::handleEvent() {
    //nothing yet... implement later
    return "";
}

void DialogueMode::draw(sf::RenderWindow &rw) {
    //nothing yet... implement later
}


void DialogueMode::update(sf::RenderWindow &rw, sf::Clock &clock)
{
    float elapsed = clock.restart().asSeconds();
    rw.clear(sf::Color::White);                                     //should this be in highest loop?
    
    //handle all input
    sf::Event event;
    while (rw.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) {
            current = current->getNext();
            if (current == nullptr) {
                deletionOrder = true;
                return;
            }
        }
        else current->handleInput(event);
    }
    current->update(elapsed);
    
    //put into drawAll function?
    rw.setView(mapView);
    
    currentMap->drawBackground(rw);
    currentMap->drawAllObjects(rw, *playerSprite);
    
    rw.setView(HUD);
    rw.draw(messageBox);
    current->draw(rw);
    rw.display();
}
