//
//  TalkNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "TalkNode.h"

TalkNode::~TalkNode() {
    std::cout << "TalkNode deleted. Text:" << getText() << "\n";
}


//void TalkNode::setNext(NodePtr ptr) {
//    next = ptr;
//}

std::string TalkNode::getText() {
    if (text.size()) {
        return text[0];
    }
    return "EMPTY TEXT";
}

TalkNode::TalkNode(const sf::Font &font, Dialogue::ID id)
: DNode(font), next(id) {
    text.setLooping(false);
}

void TalkNode::addText(sf::String&& add) {
    text.push_back(add);
}

void TalkNode::update(float elapsed) {
    auto displayString = display.getString();
    totalElapsed += elapsed;
    
    if (displayString.getSize() == text.get().getSize()) {
        return;
    }
    float time_per_letter = 0.02;
    while (totalElapsed >= time_per_letter && displayString.getSize() != text.get().getSize()) {
        displayString += text.get()[displayString.getSize()];
        totalElapsed -= time_per_letter;
    }
    display.setString(displayString);
}


void TalkNode::draw(sf::RenderWindow &rw) {
    rw.draw(display);
}

void TalkNode::clear() {
    display.setString("");
    totalElapsed = 0;
}

void TalkNode::handleInput(sf::Event &) {        //perhaps for later?
    return;
}

Dialogue::ID TalkNode::getNext(const std::vector<Condition>& cv) {
	return next;
}


//Dialogue::ID TalkNode::getNext() {
//	//completes text if still printing to screen
//    if (text.get().getSize() != display.getString().getSize()) {
//        display.setString(text.get());
//        return this;
//    }
//    //gets next DNode if complete
//    if (text.atEnd()) {
//        text.reset();
//		clear();
//        if (next) {
//            next->setPosition(getPosition());
//        }
//        return next;
//    }
//	//shifts to next sentence and returns self
//    ++text;
//    clear();
//    return this;
//}

