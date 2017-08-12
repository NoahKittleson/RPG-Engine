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

//class Trigger
//{
//public:
//	Trigger(ActionID ID, sf::FloatRect area);
//    bool intersects(sf::FloatRect) const;
//	
//	//this is just for testing right now.  Replace with proc later down the line
//	ActionID getAction() const {return successAction;};
//
//
//    ActionID proc(const std::vector<Condition>& conds) const;
//	sf::FloatRect getArea() const;
//	void drawArea(sf::RenderWindow& rw) const;
//
//private:
//    bool testConditions(const std::vector<Condition>& conds) const;
//    sf::FloatRect area;
//    ActionID successAction;
//    ActionID failureAction = ActionID::None;
//    ConditionMap prerequisites;
//    
//};

class State;
//using StatePtr = std::unique_ptr<State>;

class NewTrigger
{
public:
	NewTrigger(ConditionMap map, std::function<State*()> func)
	:prereqs(map), makePtr(func)
	{
	};
	~NewTrigger() {};
	virtual State* proc(ConditionVec& conds) const = 0;
	
protected:
	bool meetsReqs(ConditionVec& conds) const {
		bool requirementMet = true;
		for (auto && it : prereqs) {
			bool present = std::find(conds.begin(), conds.end(), it.first) == conds.end();
			if((!present && it.second) || (present && !it.second)) {
				requirementMet = false;
			}
		}
		return nullptr;
	}
	
	ConditionMap prereqs;
	std::function<State*()> makePtr;
};

class GroundTrigger : public NewTrigger
{
public:
	GroundTrigger(ConditionMap& map, std::function<State*()> func, sf::FloatRect rect)
	: NewTrigger(map, func), area(rect)
	{
	}
	
	virtual State* proc(ConditionVec& conds) const override {
		if (meetsReqs(conds)) {
			return makePtr();					//problem here is that you can't have unique_ptr with incomplete type
		}
		return nullptr;
	}
	
	bool intersects(std::vector<sf::FloatRect>& collision) {
		for (const auto & it : collision) {
			if(it.intersects(area)) {
				return true;
			}
		}
		return false;
	}
	
	operator sf::FloatRect() const {return area;};
	void drawArea(sf::RenderWindow& rw) const {
		sf::RectangleShape rect;
		rect.setFillColor(sf::Color(85,26,139, 150));					//translucent purple
		rect.setSize(sf::Vector2f(area.width, area.height));
		rect.setPosition(area.left, area.top);
		rw.draw(rect);
	};
	
private:
	sf::FloatRect area;
};

//will be attached to DNodes or BattleOutcomes
class AttachedTrigger : public NewTrigger {
public:
	AttachedTrigger(ConditionMap map, std::function<State*()> func)
	: NewTrigger(map, func)
	{
	}
	
	virtual State* proc(ConditionVec& conds) const override {
		if (meetsReqs(conds)) {
			return makePtr();
		}
		return nullptr;
	}
private:
	
	
};

//also consider using this for storing the actions that triggers need to execute:
template <typename T>
class Order
{
public:
	Order(T obj, std::function<void(T&)> func) : obj(obj), func(func) {};
	void execute() { func(obj); };
	
private:
	T obj;
	std::function<void(T&)> func;
};









//Things to do:
//1. Make Trigger a more general base class so that I can have non-area triggers

