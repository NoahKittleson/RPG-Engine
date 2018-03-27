//
//  StatusEffect.cpp
//  Overworld
//
//  Created by Noah Kittleson on 3/19/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "StatusEffect.hpp"

void StatusEffect::textify(sf::Text& text) {
	
}


Stun::Stun(char duration) : StatusEffect("Stun")  {
	displayColor = sf::Color(200,200,0);
	buff = false;
}

Stun Stun::operator+(const Stun& other) {
	if (other.duration > duration) {
		duration = other.duration;
	} return *this;
}

void Stun::textify(sf::Text& text) {
	text.setColor(displayColor);
	std::ostringstream ss;
	 ss << name <<": " << duration << "\n";
	text.setString(ss.str());
}

void AdditiveEffect::textify(sf::Text& text) {
	text.setColor(displayColor);
	std::ostringstream ss;
	ss << name <<": " << amount << "\n";
	text.setString(ss.str());
}

AdditiveEffect AdditiveEffect::operator+(const AdditiveEffect& other) {
	this->amount += other.amount;
	return *this;
}

Bleed::Bleed(int amount) : AdditiveEffect("Bleed", amount) {
	//nothing here
}
