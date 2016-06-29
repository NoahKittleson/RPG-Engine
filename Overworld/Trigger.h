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
//#include "State.h"
//#include "DialogueMode.h"
//#include "BattleMode.h"

enum class DataType {Fight, Talk};

class State;

union TriggerData
{
public:
    TriggerData(DNode* a)
    : conversation(a) {}
    TriggerData(std::vector<Character> b)
    : enemyVec(b) {}
    
    DNode* conversation;
    std::vector<Character> enemyVec;
};


class Trigger
{
public:
    Trigger(sf::FloatRect, std::vector<Character> enemies);
    Trigger(sf::FloatRect, DNode* text);
    
    bool intersects(sf::FloatRect) const;
    State* procTrigger(sf::RenderWindow &rw) const;        //returns new state from trigger.
    
private:
    sf::FloatRect area;
    DataType type;
    TriggerData data;
    
};