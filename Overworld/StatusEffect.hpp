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
	StatusEffect(std::string str): name(str) {};
	virtual void textify(sf::Text& text) = 0;
	
protected:
	const std::string name;
	sf::Color displayColor = sf::Color::Black;
	bool buff;
};

class Stun : public StatusEffect
{
public:
	Stun(char duration);
	Stun operator+(const Stun& other);
	virtual void textify(sf::Text& text) override;

private:
	char duration;
};
