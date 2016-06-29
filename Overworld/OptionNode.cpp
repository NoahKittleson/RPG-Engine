//
//  OptionNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "OptionNode.h"


OptionNode::OptionNode(sf::Font &font)
: DNode(font)
{
    text.setLooping(true);
}

void OptionNode::addText(sf::String&& rString, DNode* ptr)
{
    text.emplace_back(std::pair<sf::String, DNode*>(rString, ptr));
}

void OptionNode::update(float elapsed)
{
    return;
}

void OptionNode::draw(sf::RenderWindow &rw)
{
    sf::Vector2f position = display.getPosition();
    
    display.setColor(sf::Color::Red);
    for (char iii {0}; iii != text.size(); ++iii) {         //a little ghetto... perhaps include a forAll in IterVector
        display.setString(text.get().first);
        rw.draw(display);
        display.setColor(sf::Color::Black);
        display.setPosition(position.x, display.getPosition().y+40);        //might be a slighty better way to do this.
        ++text;
    }
    display.setPosition(position);
}

void OptionNode::handleInput(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
        ++text;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
        --text;
    }
}

DNode* OptionNode::getNext()
{
    DNode* returnVal = text.get().second;
    text.reset();
    return returnVal;
}