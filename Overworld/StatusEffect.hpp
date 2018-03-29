//
//  StatusEffect.hpp
//  Overworld
//
//  Created by Noah Kittleson on 3/19/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Character.h"

class StatusEffect
{
public:
//	enum Type {Poison, Bleed, Stun, DmgBuff};
//	virtual Type getType() const = 0;
	virtual void textify(sf::Text& text) const = 0;
	virtual void update() { if(!amount) done = true; };
	virtual void effect(std::shared_ptr<Character> character) const { return; };
	bool isDone() const {return done;};
	
protected:
	enum Timing {  turnStart, attackDmgMod, attackDmgMult, defendDmgMod, defendDmgMult, afterEffect };
	StatusEffect(std::string str, bool buff, int amount, Timing whenToApply);
	Timing applicationTiming;
	const std::string name;
	sf::Color displayColor = sf::Color::Black;
	bool buff;
	bool done = false;
	int amount;
};

//~~~~~~~~~~~AdditiveEffect~~~~~~~~~~~~//
class AdditiveEffect : public StatusEffect
{
public:
	virtual void textify(sf::Text& text) const override;
	virtual AdditiveEffect operator+(const AdditiveEffect& other);
	
protected:
	AdditiveEffect(std::string name, bool pos, int amount, Timing when) : StatusEffect(name, pos, amount, when) {};
};

//~~~~~~~~~~NonAdditiveEffect~~~~~~~~~~//
class NonAdditiveEffect : public StatusEffect
{
public:
	virtual void textify(sf::Text& text) const override;
	virtual NonAdditiveEffect operator+(const NonAdditiveEffect& other);
	
protected:
	NonAdditiveEffect(std::string name, bool pos, int quantity, Timing when) : StatusEffect(name, pos, quantity, when) {};
};

//~~~~~~~~~~MultiplierEffect~~~~~~~~~~//
class MultiplierEffect : public NonAdditiveEffect
{
public:
	virtual void textify(sf::Text& text) const override;
	virtual void update() override;
	
protected:
	MultiplierEffect(std::string name, bool pos, int quantity, Timing when, float mult) : NonAdditiveEffect(name, pos, quantity, when), multiplier(mult) {};
	float multiplier;
};

