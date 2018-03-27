//
//  Statuses.hpp
//  Overworld
//
//  Created by Noah Kittleson on 3/27/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "StatusEffect.hpp"

class Bleed : public AdditiveEffect
{
public:
	Bleed(int amount);
};

class Stun : public NonAdditiveEffect
{
public:
	Stun(char duration);
	virtual void textify(sf::Text& text) const override;
	virtual void tickDown() override;
};

class Poison : public NonAdditiveEffect
{
public:
	Poison(int amount);
};
