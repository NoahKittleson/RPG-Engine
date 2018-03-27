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

void Stun::tickDown() {
	--amount;
	StatusEffect::tickDown();
}

void Stun::textify(sf::Text& text) const {
	text.setColor(displayColor);
	std::ostringstream ss;
	ss << "Stunned: " << amount << " turns\n";
	text.setString(ss.str());
}

Stun::Stun(char duration) : NonAdditiveEffect("Stun", false, duration) {
	displayColor = sf::Color(200,200,0);
	buff = false;
}

Poison::Poison(int amount) : NonAdditiveEffect("Poison", false, amount) {
	displayColor = sf::Color(0,153,0);
}


Bleed::Bleed(int amount) : AdditiveEffect("Bleed", false, amount) {
	displayColor = sf::Color::Red;
}
