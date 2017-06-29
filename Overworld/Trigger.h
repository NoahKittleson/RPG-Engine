//
//  Trigger.h
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "DNode.h"
#include "Character.h"
#include "Conditions.cpp"

enum class ActionID {Fight, Talk, None};
using ConditionMap = std::map<Condition, bool>;

class Trigger
{
public:
	//base:
	Trigger(ActionID ID, sf::FloatRect area) {
		this->area = area;
		this->successAction = ID;
	};
    bool intersects(sf::FloatRect) const;
	
	//this is just for testing right now.  Replace with proc later down the line
	ActionID getAction() {return successAction;};


    ActionID proc(const std::vector<Condition>& conds) const;
	sf::FloatRect getArea() const;
	void drawArea(sf::RenderWindow& rw) const;

private:
    bool testConditions(const std::vector<Condition>& conds) const;
    sf::FloatRect area;
    ActionID successAction;
    ActionID failureAction = ActionID::None;
    ConditionMap prerequisites;
    
};

//Things to do:
//1. Make Trigger a more general base class so that I can have non-area triggers

