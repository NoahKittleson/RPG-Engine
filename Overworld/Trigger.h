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
enum class Condition {FoughtWheat, ChangedMap};
using ConditionMap = std::map<Condition, bool>;

class Trigger
{
public:
    //base:
    bool intersects(sf::IntRect) const;
    ActionID proc(ConditionMap conds) const;

private:
    bool testConditions(ConditionMap conds) const;
    sf::IntRect area;
    ActionID successAction;
    ActionID failureAction = ActionID::None;
    ConditionMap prerequisites;
    
};

