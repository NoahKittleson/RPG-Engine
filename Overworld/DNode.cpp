//
//  DNode.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/17/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "DNode.h"

DNode::DNode(const sf::Font& font) {
    display.setFont(font);
    display.setColor(sf::Color::Black);
    display.setString("");
}

void DNode::setPosition(float x, float y) {
    display.setPosition(x, y);
}

void DNode::setPosition(sf::Vector2f xy) {
    display.setPosition(xy);
}

sf::Vector2f DNode::getPosition() const {
    return display.getPosition();
}

void DNode::clear() {
    display.setString("");
}

void DNode::addConsequence(Condition add) {
	consequences.push_back(add);
}

//void DNode::addPreReq(Condition add) {
//	consequences.push_back(add);
//}

void DNode::resolveConditions(std::vector<Condition>& cv) const {
	for (auto const & it : consequences) {
		if (std::find(cv.begin(), cv.end(), it) == cv.end()) {
			cv.push_back(it);
			std::cout << "Condition Added\n";
		}
	}
}

//bool DNode::checkConditions(const std::vector<Condition>& cv) const {
//	for (auto const & it : preReqs) {
//		if (std::find(cv.begin(), cv.end(), it) == cv.end()) {
//			return false;
//		}
//	}
//	return true;
//}

