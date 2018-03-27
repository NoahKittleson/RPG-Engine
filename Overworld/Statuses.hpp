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



