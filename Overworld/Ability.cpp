//
//  Ability.cpp
//  BattleMode
//
//  Created by Noah Kittleson on 1/17/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "Ability.h"


Ability::Ability()
{
    abilityName.setString("EMPTY");
    abilityName.setColor(sf::Color::Black);
    abilityName.setPosition(0, 0);
    abilityDescription.setString("EMPTY");
    abilityDescription.setColor(sf::Color::Black);
    abilityDescription.setPosition(0, 0);
}

Ability::Ability(std::string name, std::string desc, float BaseDmg, bool multiTarg, bool AllyTarget, const sf::Texture& tex)
: hitAnimation(&tex), multiTarget(multiTarg), allyTargetPref(AllyTarget), baseDamage(BaseDmg)
{
    abilityName.setString(name);
    abilityName.setColor(sf::Color::Black);
    abilityName.setPosition(0, 0);
    abilityDescription.setString(desc);
    abilityDescription.setColor(sf::Color::Black);
    abilityDescription.setPosition(600, 100);
}

void Ability::draw(sf::RenderWindow &rw)
{
    rw.draw(abilityName);
}

void Ability::drawDesc(sf::RenderWindow &rw)
{
    rw.draw(abilityDescription);
    drawReqs(rw);
}

void Ability::setColor(sf::Color color)
{
    abilityName.setColor(color);
}

void Ability::setPosition(float x, float y)
{
    abilityName.setPosition(x, y);
}

void Ability::addProperty(Ability::Property prop, float num, bool onSelf)
{
	if (onSelf) {
		selfProperties.emplace(std::pair<Ability::Property, float>(prop, num));
	} else {
    	properties.emplace(std::pair<Ability::Property, float>(prop, num));
	}
}

void Ability::addReq(Ability::Requirement req, float num)
{
    requirements.emplace(std::pair<Ability::Requirement, float>(req, num));
}

void Ability::setMultiplier(Ability::DamageMultiplier multi, float percent)
{
    dmgMulti = (std::pair<Ability::DamageMultiplier, float>(multi, percent));
}

void Ability::setDamageType(Ability::DamageType type)
{
    dmgType = type;
}

void Ability::setFont(const sf::Font &font)
{
    abilityDescription.setFont(font);
    abilityName.setFont(font);
}

void Ability::addAfterEffect(Ability::AfterEffect effect, float percent)
{
    afterEffects.emplace(std::pair<Ability::AfterEffect, float>(effect, percent));
}

bool Ability::hasProperty(const Ability::Property &type) const
{
    if (properties.find(type) != properties.end()) {
        return true;
    }
    return false;
}

void Ability::toggleGray(bool gray)
{
    if (gray) {
        abilityName.setColor(sf::Color(128,128,128));
        abilityDescription.setColor(sf::Color(128,128,128));
        return;
    }
    abilityName.setColor(sf::Color::Black);
    abilityDescription.setColor(sf::Color::Black);
}

bool Ability::isGrayedOut()
{
    if (abilityDescription.getColor() == sf::Color(128,128,128)) {
        return true;
    }
    else return false;
}


void Ability::drawReqs(sf::RenderWindow &rw)
{
    sf::Text Reqs = abilityDescription;
    Reqs.move(0, -100);
    
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
    Reqs.setString(ss.str());
	Reqs.setFont(*abilityName.getFont());
    rw.draw(Reqs);
}

std::string Ability::getName() const {
	return abilityName.getString();
}















