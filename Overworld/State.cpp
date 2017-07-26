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
    --instances;
//    if (instances <= 0) {
//        delete playerSprite;
//        delete currentMap;
//    }
}

State::State() {
    ++instances;
}

void State::addToStack(StatePtr&& addMe)
{
	stack->addState(std::move(addMe));
}

bool State::checkDeletion()
{
    return deletionOrder;
}

const ResourceHolder State::resources;
StateStack* State::stack;
std::unique_ptr<MapSection> State::currentMap;
std::vector<Character> State::party;
std::unique_ptr<PlayerObject> State::player;
std::vector<Condition> State::conditions;
