//
//  OptionNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "OptionNode.h"


OptionNode::OptionNode(const sf::Font &font)
: DNode(font)
{
    text.setLooping(true);
    display.setColor(sf::Color::Black);
}

OptionNode::~OptionNode() {
    std::cout << "OptionNode deleted. Text:" << getText() << "\n";
}

void OptionNode::addText(sf::String&& rString, Dialogue::ID next) {
    text.emplace_back(std::pair<sf::String, Dialogue::ID>(rString, next));
}

void OptionNode::update(float elapsed) {
    return;
}

void OptionNode::draw(sf::RenderWindow &rw) {
    sf::Vector2f position = display.getPosition();
    
    for (char iii {0}; iii != text.size(); ++iii) {
        display.setString(text[iii].first);
        text.getIndex() == iii ? display.setColor(sf::Color::Red) : display.setColor(sf::Color::Black);
        rw.draw(display);
        display.setPosition(position.x, position.y+40);
    }
    display.setPosition(position);
}

void OptionNode::handleInput(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
        ++text;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
        --text;
    }
}

Dialogue::ID OptionNode::getNext() {
	return text.get().second;
}
//	NodePtr returnVal = std::make_shared<DNode>(text.get().second);
//	text.reset();
//    if (returnVal) {
//        returnVal->setPosition(getPosition());
//    }
//    return returnVal;
//}

std::string OptionNode::getText() {
    if (text.size()) {
        return text[0].first.toAnsiString();
    }
    return "EMPTY TEXT";
}


