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

enum class DataType {Fight, Talk};


union TriggerData
{
public:
    TriggerData(DNode* a)
    : conversation(a) {}
    TriggerData(std::vector<Character> b)
    : enemyVec(b) {}
    
    //I need this, but I don't know why...
    ~TriggerData() {};
    
    DNode* conversation;
    std::vector<Character> enemyVec;
};


class Trigger
{
public:
    Trigger(sf::FloatRect, std::vector<Character> enemies);
    Trigger(sf::FloatRect, DNode* text);
    
    bool intersects(sf::FloatRect) const;
    DataType getDataType() const;
    TriggerData getData() const;
    //State* procTrigger(sf::RenderWindow &rw) const;        //returns new state from trigger.
    
    DataType type;
    TriggerData data;
    
private:
    sf::FloatRect area;

    
};