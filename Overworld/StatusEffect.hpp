//
//  StatusEffect.hpp
//  Overworld
//
//  Created by Noah Kittleson on 3/19/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"

class StatusEffect
{
public:
	virtual void textify(sf::Text& text) const = 0;
	virtual void tickDown() { if(!amount) done = true; };
	bool isDone() const {return done;};
	
protected:
	StatusEffect(std::string str, bool pos, int amount): name(str), buff(pos), amount(amount) {};
	const std::string name;
	sf::Color displayColor = sf::Color::Black;
	bool buff;
	bool done = false;
	int amount;
};

class AdditiveEffect : public StatusEffect
{
public:
	virtual void textify(sf::Text& text) const override;
	virtual AdditiveEffect operator+(const AdditiveEffect& other);
	
protected:
	AdditiveEffect(std::string name, bool pos, int quantity) : StatusEffect(name, pos, quantity) {};
};

class NonAdditiveEffect : public StatusEffect
{
public:
	virtual void textify(sf::Text& text) const override;
	virtual NonAdditiveEffect operator+(const NonAdditiveEffect& other);
	
protected:
	NonAdditiveEffect(std::string name, bool pos, int quantity) : StatusEffect(name, pos, quantity) {};
};

