//
//  Statuses.cpp
//  Overworld
//
//  Created by Noah Kittleson on 3/27/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "Statuses.hpp"

void Stun::update() {
	--amount;
	StatusEffect::update();
}

void Stun::textify(sf::Text& text) const {
	text.setColor(displayColor);
	std::ostringstream ss;
	ss << "Stunned: " << amount << " turns\n";
	text.setString(ss.str());
}

Stun::Stun(char duration) : NonAdditiveEffect("Stun", false, duration, turnStart) {
	displayColor = sf::Color(200,200,0);
	buff = false;
}

Poison::Poison(int amount) : NonAdditiveEffect("Poison", false, amount, turnStart) {
	displayColor = sf::Color(0,153,0);
}

void Poison::effect(std::shared_ptr<Character> character) const {
	character->adjustHealth(amount);
}

Bleed::Bleed(int amount) : AdditiveEffect("Bleed", false, amount, turnStart) {
	displayColor = sf::Color::Red;
}

void Bleed::effect(std::shared_ptr<Character> character) const {
	character->adjustHealth(amount);
}

DmgMultiplier::DmgMultiplier(float mult, int length) : MultiplierEffect("Multiplier", true, length, attackDmgMult, mult) {
	displayColor = sf::Color(150,150,150);		//this might be gray?  I don't even know
}

void DmgMultiplier::textify(sf::Text& text) const {
	text.setColor(displayColor);
	std::ostringstream ss;
	ss << "+" << amount << "% Dmg Buff\n";
	text.setString(ss.str());
}

void DmgMultiplier::update() {
	amount--;
	StatusEffect::update();
}

DmgVulnerability::DmgVulnerability(float mult, int length) : MultiplierEffect("Vulnerability", false, length, defendDmgMult, mult) {
	displayColor = sf::Color::Black;			//what color to make this?
}

void DmgVulnerability::textify(sf::Text& text) const {
	text.setColor(displayColor);
	std::ostringstream ss;
	ss << "+" << amount << "% Dmg Taken\n";
	text.setString(ss.str());
}

void DmgVulnerability::update() {
	amount--;
	StatusEffect::update();
}
