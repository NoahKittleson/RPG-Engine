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
    _AbilityName.setString("EMPTY");
    _AbilityName.setColor(sf::Color::Black);
    _AbilityName.setPosition(0, 0);
    _AbilityDescription.setString("EMPTY");
    _AbilityDescription.setColor(sf::Color::Black);
    _AbilityDescription.setPosition(0, 0);
}

Ability::Ability(std::string name, std::string desc, float BaseDmg, bool multiTarg, bool AllyTarget, const sf::Texture& tex)
: hitAnimation(&tex), _multiTarget(multiTarg), _allyPrimaryTarget(AllyTarget), _baseDamage(BaseDmg)
{
    _AbilityName.setString(name);
    _AbilityName.setColor(sf::Color::Black);
    _AbilityName.setPosition(0, 0);
    _AbilityDescription.setString(desc);
    _AbilityDescription.setColor(sf::Color::Black);
	std::cout << "Ability copied.\n";
    _AbilityDescription.setPosition(600, 100);
}

void Ability::draw(sf::RenderWindow &rw)
{
    rw.draw(_AbilityName);
}

void Ability::drawDesc(sf::RenderWindow &rw)
{
    rw.draw(_AbilityDescription);
    drawReqs(rw);
}

void Ability::setColor(sf::Color color)
{
    _AbilityName.setColor(color);
}

void Ability::setPosition(float x, float y)
{
    _AbilityName.setPosition(x, y);
}

void Ability::setProperties(Ability::Properties prop, float num)
{
    AbilityProperties.insert(std::pair<Ability::Properties, float>(prop, num));
}

void Ability::setReq(Ability::Requirements req, float num)
{
    AbilityRequirements.insert(std::pair<Ability::Requirements, float>(req, num));
}

void Ability::setMultiplier(Ability::DamageMultipliers multi, float percent)
{
    AbilityDmgMulti = (std::pair<Ability::DamageMultipliers, float>(multi, percent));
}

void Ability::setDamageType(Ability::DamageType type)
{
    _dmgType = type;
}

void Ability::setFont(const sf::Font &font)
{
    _AbilityDescription.setFont(font);
    _AbilityName.setFont(font);
}

void Ability::setAfterEffects(Ability::AfterEffects effect, float percent)
{
    AbilityAfterEffects.insert(std::pair<Ability::AfterEffects, float>(effect, percent));
}

bool Ability::hasProperty(const Ability::Properties &type) const
{
    if (AbilityProperties.find(type) != AbilityProperties.end()) {
        return true;
    }
    return false;
}

void Ability::toggleGray(bool gray)
{
    if (gray) {
        _AbilityName.setColor(sf::Color(128,128,128));
        _AbilityDescription.setColor(sf::Color(128,128,128));
        return;
    }
    _AbilityName.setColor(sf::Color::Black);
    _AbilityDescription.setColor(sf::Color::Black);
}

bool Ability::isGrayedOut()
{
    if (_AbilityDescription.getColor() == sf::Color(128,128,128)) {
        return true;
    }
    else return false;
}


void Ability::drawReqs(sf::RenderWindow &rw)
{
    sf::Text Reqs = _AbilityDescription;
    Reqs.move(0, -100);
    
    std::ostringstream ss;
    
    for (const auto & it: AbilityRequirements) {
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
    rw.draw(Reqs);
}

std::string Ability::getName() const {
	return _AbilityName.getString();
}















