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
#include "Conditions.hpp"

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

class Trigger
{
public:
	Trigger(ConditionMap map, std::function<State*()> func);
	~Trigger() {};
	virtual State* proc(ConditionVec& conds) const = 0;
	
protected:
	bool meetsReqs(ConditionVec& conds) const;
	
	ConditionMap prereqs;
	std::function<State*()> makePtr;
};



class GroundTrigger : public Trigger
{
public:
	GroundTrigger(ConditionMap& map, std::function<State*()> func, sf::FloatRect rect);
	virtual State* proc(ConditionVec& conds) const override;
	bool intersects(std::vector<sf::FloatRect>& collision);
	operator sf::FloatRect() const;
	void drawArea(sf::RenderWindow& rw) const;
	
private:
	sf::FloatRect area;
};



//will be attached to DNodes or BattleOutcomes
class AttachedTrigger : public Trigger {
public:
	AttachedTrigger(ConditionMap map, std::function<State*()> func);
	virtual State* proc(ConditionVec& conds) const override;

};


//maybe later I'll use this...
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

