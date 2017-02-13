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

enum class ActionID {fight, talk};
class Condition; //needs defining and implementing

class Trigger
{
public:
    //base:
    bool intersects(sf::IntRect) const;
    ActionID proc() const;

private:
    sf::IntRect area;
    ActionID whatItDoes;
    std::map<Condition, bool> prerequisites;
    
};


class Condition
{
public:
    
private:
    
};
