//
//  StateStack.cpp
//  Overworld
//
//  Created by Noah Kittleson on 11/20/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "State.h"


State::~State()
{
    
}

void State::addToStack(State* addMe)
{
    stack->addState(addMe);
}

void State::addToStackAndBreak(State *addMe)
{
    looping = false;
    stack->addState(addMe);
}

void State::setStack(StateStack &SS)
{
    stack = &SS;
}

bool State::checkDeletion()
{
    return deletionOrder;
}

const ResourceHolder State::resources;
StateStack* State::stack;
MapSection* State::currentMap;
std::list<Character> State::party;
Player State::playerSprite;
