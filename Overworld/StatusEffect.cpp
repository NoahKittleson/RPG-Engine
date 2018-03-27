//
//  StatusEffect.cpp
//  Overworld
//
//  Created by Noah Kittleson on 3/19/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "StatusEffect.hpp"

void AdditiveEffect::textify(sf::Text& text) const {
	text.setColor(displayColor);
	std::ostringstream ss;
	ss << name <<": " << amount << "\n";
	text.setString(ss.str());
}

AdditiveEffect AdditiveEffect::operator+(const AdditiveEffect& other) {
	this->amount += other.amount;
	return *this;
}

void NonAdditiveEffect::textify(sf::Text& text) const {
	text.setColor(displayColor);
	std::ostringstream ss;
	ss << name <<": " << amount << "\n";
	text.setString(ss.str());
}

NonAdditiveEffect NonAdditiveEffect::operator+(const NonAdditiveEffect& other) {
	if (other.amount > this->amount) {
		amount = other.amount;
	} return *this;
}
