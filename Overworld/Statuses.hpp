//
//  Statuses.hpp
//  Overworld
//
//  Created by Noah Kittleson on 3/27/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "StatusEffect.hpp"

//~~~~~~~~~~~Bleed~~~~~~~~~~~~//
class Bleed : public AdditiveEffect
{
public:
	Bleed(int amount);
	void effect(std::shared_ptr<Character> character) const override;
};

//~~~~~~~~~~~Stun~~~~~~~~~~~~//
class Stun : public NonAdditiveEffect
{
public:
	Stun(char duration);
	virtual void textify(sf::Text& text) const override;
	virtual void update() override;
};

//~~~~~~~~~~~Poison~~~~~~~~~~~//
class Poison : public NonAdditiveEffect
{
public:
	Poison(int amount);
	void effect(std::shared_ptr<Character> character) const override;
};

//~~~~~~~~~DmgMultiplier~~~~~~~~~//
class DmgMultiplier : public MultiplierEffect
{
public:
	DmgMultiplier(float multiplier, int length);
	virtual void textify(sf::Text& text) const override;
	virtual void update() override;
};

//~~~~~~~~~DmgVulnerability~~~~~~~~//
class DmgVulnerability : public MultiplierEffect
{
public:
	DmgVulnerability(float multiplier, int length);
	virtual void textify(sf::Text& text) const override;
	virtual void update() override;
};

//complications-
//--Are damage multipliers really even statuseffects?
//--Use enums instead of text strings for better checking later? Also, are the strings ever used in a real way?
//--effect() seems like it is only very useful for things that change health or mana.  Not for stun 





