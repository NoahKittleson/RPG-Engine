//
//  Ability.cpp
//  BattleMode
//
//  Created by Noah Kittleson on 1/17/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "Ability.hpp"

Ability::Ability(std::string name, std::string desc, float BaseDmg, bool multiTarg, bool AllyTarget, const sf::Texture& tex)
: hitAnimation(&tex), multiTarget(multiTarg), allyTargetPref(AllyTarget), baseDamage(BaseDmg)
{
//    abilityName.setString(name);
//    abilityName.setColor(sf::Color::Black);
//    abilityName.setPosition(0, 0);
    abilityDescription.setString(desc);
    abilityDescription.setColor(sf::Color::Black);
    abilityDescription.setPosition(600, 100);
	determineReqs();
}

void Ability::draw(sf::RenderWindow &rw) const {
    rw.draw(abilityName);
}

void Ability::drawDesc(sf::RenderWindow &rw) const {
    rw.draw(abilityDescription);
	rw.draw(abilityReqs);
}

void Ability::setColor(sf::Color color) {
    abilityName.setColor(color);
}

void Ability::setPosition(float x, float y) {
    abilityName.setPosition(x, y);
}

void Ability::addProperty(Ability::Property prop, float num, bool onSelf) {
	if (onSelf) {
		selfProperties.emplace(std::pair<Ability::Property, float>(prop, num));
	} else {
    	properties.emplace(std::pair<Ability::Property, float>(prop, num));
	}
}

void Ability::addReq(Ability::Requirement req, float num) {
    requirements.emplace(std::pair<Ability::Requirement, float>(req, num));
}

void Ability::setMultiplier(Ability::DamageMultiplier multi, float percent) {
    dmgMulti = (std::pair<Ability::DamageMultiplier, float>(multi, percent));
}

void Ability::setDamageType(Ability::DamageType type) {
    dmgType = type;
}

void Ability::setFont(const sf::Font &font) {
    abilityDescription.setFont(font);
    abilityName.setFont(font);
	abilityReqs.setFont(font);
}

void Ability::addAfterEffect(Ability::AfterEffect effect, float percent) {
    afterEffects.emplace(std::pair<Ability::AfterEffect, float>(effect, percent));
}

bool Ability::hasProperty(const Ability::Property &type) const {
    if (properties.find(type) != properties.end()) {
        return true;
    }
    return false;
}

void Ability::determineReqs() {
	abilityReqs.setPosition(abilityDescription.getPosition());
    abilityReqs.move(0, 50);
	abilityReqs.setColor(sf::Color::Black);
	
	if (requirements.empty()) {
		abilityReqs.setString("No cost");
		return;
	}
    
    std::ostringstream ss;
    for (const auto & it: requirements) {
        switch (it.first) {
            case ManaCost:
                ss << "ManaCost: " << it.second << "\n";
                break;
                
            case HealthCost:
                ss << "HPCost: " << it.second << "\n";
                break;
                
            default:
                break;
        }
    }
    abilityReqs.setString(ss.str());
}

std::string Ability::getName() const {
	return abilityName.getString();
}

bool Ability::isAttackSpell() const {
	return allyTargetPref;
}














