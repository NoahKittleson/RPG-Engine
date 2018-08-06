//
//  TalkNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "TalkNode.h"

TalkNode::TalkNode(const sf::Font &font, Dialogue::ID id)
: DNode(font, id) {
	text.setLooping(false);
}

TalkNode::~TalkNode() {
    std::cout << "TalkNode deleted. Text:" << getText() << "\n";
}

std::string TalkNode::getText() {
    if (text.size()) {
        return text[0];
    }
    return "EMPTY TEXT";
}

void TalkNode::addText(sf::String&& add) {
	text.push_back(add);

	int lineBreakAfter = 50;
	int atCharacter = 50;
	while (text.back().getSize() > atCharacter) {
		if (text.back()[atCharacter] == ' ') {
			text.back()[atCharacter] = '\n';
			atCharacter += lineBreakAfter;
		} else {
			++atCharacter;
		}
	}

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
	//completes text if still printing to screen
	if (text.get().getSize() != display.getString().getSize()) {
		display.setString(text.get());
		return ID;
	}
	//gets next DNode if complete
	if (text.atEnd()) {
		text.reset();
		clear();
		for (const auto & path : potentialPaths) {
			if (path.isSatisfied(cv)) {
				return path.getNext();
			}
		}
		return Dialogue::None;
	}
	//shifts to next sentence and returns self since it is not done, but not still printing to screen
	++text;
	clear();
	return ID;
}

void TalkNode::addPath(DPath path) {
	potentialPaths.push_back(path);
}


