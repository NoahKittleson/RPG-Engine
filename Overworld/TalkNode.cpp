//
//  TalkNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "TalkNode.h"

TalkNode::TalkNode(const sf::Font &font, Dialogue::ID id)
: DNode(font, id){
	text.setLooping(false);
	speakerText.setFont(font);
	speakerText.setColor(sf::Color::Black);
	speakerText.setString(Dialogue::speakerToText(text.get().speakerID));
}

TalkNode::~TalkNode() {
    std::cout << "TalkNode deleted. Text:" << getText() << "\n";
}

std::string TalkNode::getText() {
    if (text.size()) {
        return text[0].string;
    }
    return "EMPTY TEXT";
}

void TalkNode::addText(sf::String&& string, Dialogue::Speaker speaker) {
	text.emplace_back(string, speaker);

	int lineBreakAfter = 50;
	int atCharacter = 50;
	while (text.back().string.getSize() > atCharacter) {
		if (text.back().string[atCharacter] == ' ') {
			text.back().string[atCharacter] = '\n';
			atCharacter += lineBreakAfter;
		} else {
			++atCharacter;
		}
	}

}

void TalkNode::update(float elapsed, AudioHandler& audio) {
    auto displayString = display.getString();
    totalElapsed += elapsed;
	
    if (displayString.getSize() == text.get().string.getSize()) {
        return;
    }
    float time_per_letter = 0.02;
    while (totalElapsed >= time_per_letter && displayString.getSize() != text.get().string.getSize()) {
        displayString += text.get().string[displayString.getSize()];
        totalElapsed -= time_per_letter;
		audio.playSound(SoundID::shine);
    }
    display.setString(displayString);
}


void TalkNode::draw(sf::RenderWindow &rw) {
    rw.draw(display);
	rw.draw(speakerText);
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
	if (text.get().string.getSize() != display.getString().getSize()) {
		display.setString(text.get().string);
		speakerText.setString(Dialogue::speakerToText(text.get().speakerID));
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

void TalkNode::setPosition(sf::Vector2f xy) {
	DNode::setPosition(xy);
	speakerText.setPosition(xy.x+540, xy.y-55);				//magic numbers
}

void TalkNode::setPosition(float x, float y) {
	DNode::setPosition(x, y);
	speakerText.setPosition(x+540, y-55);
}


