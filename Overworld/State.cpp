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
    delete playerSprite;
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


bool State::checkDeletion()
{
    return deletionOrder;
}

const ResourceHolder State::resources;
StateStack* State::stack;
MapSection* State::currentMap;
std::vector<Character> State::party;
Player* State::playerSprite;
