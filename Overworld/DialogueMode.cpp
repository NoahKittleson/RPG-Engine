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
    std::cout << "DNode is as address: " << current << "\n";
    std::cout << "DNode has a string that says: " << current->display.getString().toAnsiString() << "\n";
    std::cout << "DNode has a font: " << (current->display.getFont() ? "true" : "false") << "\n";
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


//void DManager::update(sf::RenderWindow &rw, float elapsed, sf::Event &event)
void DialogueMode::update(sf::RenderWindow &rw, sf::Clock &clock)
{
    float elapsed = clock.restart().asSeconds();
    rw.clear(sf::Color::White);                                     //should this be in highest loop?
    
    //handle all input
    sf::Event event;
    while (rw.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            current = current->getNext();
            if (current == nullptr) {               //change this...
                deletionOrder = true;
                return;
            }
        }
        else current->handleInput(event);
    }
    //current->update(elapsed);
    
    //put into drawAll function?
    rw.setView(mapView);
    
    currentMap->drawAllObjects(rw, playerSprite);
    
    rw.setView(HUD);
    rw.draw(messageBox);
    if (current != nullptr) {
        current->draw(rw);
    }
    rw.display();
}