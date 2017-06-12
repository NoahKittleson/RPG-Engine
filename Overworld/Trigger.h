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

enum class ActionID {Fight, Talk, None};
enum class Condition {First, FoughtWheat, ChangedMap, Last};
using ConditionMap = std::map<Condition, bool>;

class Trigger
{
public:
    //base:
    bool intersects(sf::FloatRect) const;
    ActionID proc(const std::vector<Condition>& conds) const;
	sf::FloatRect getArea() const;

private:
    bool testConditions(const std::vector<Condition>& conds) const;
    sf::FloatRect area;
    ActionID successAction;
    ActionID failureAction = ActionID::None;
    ConditionMap prerequisites;
    
};

//Things to do:
//1. Make Trigger a more general base class so that I can have non-area triggers

