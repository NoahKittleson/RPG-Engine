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

using ConditionMap = std::map<Condition, bool>;
using ConditionVec = std::vector<Condition>;

class Trigger
{
public:
	Trigger(ActionID ID, sf::FloatRect area);
    bool intersects(sf::FloatRect) const;
	
	//this is just for testing right now.  Replace with proc later down the line
	ActionID getAction() const {return successAction;};


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


class NewTrigger
{
public:
	virtual StatePtr proc(ConditionVec& conds) = 0;
	
protected:
	//info for new state
	ConditionMap prereqs;
};

class GroundTrigger : public NewTrigger
{
public:
	virtual StatePtr proc(ConditionVec& conds) override {
		bool requirementMet = true;
		for (auto && it : prereqs) {
			bool present = std::find(conds.begin(), conds.end(), it.first) == conds.end();
			if((!present && it.second) || (present && !it.second)) {
				requirementMet = false;
			}
		}
	}
};






//Things to do:
//1. Make Trigger a more general base class so that I can have non-area triggers

