//
//  StateStack.cpp
//  Overworld
//
//  Created by Noah Kittleson on 11/21/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "StateStack.h"

StateStack::~StateStack()
{
    while (!gameStateStack.empty()) {
        //formerly delete
    }
}

void StateStack::popTop()
{
    gameStateStack.pop();
}

void StateStack::addState(StatePtr&& addMe)
{
    if (addMe) {
		gameStateStack.push(std::move(addMe));
    }
}

void StateStack::clear()
{
	while (!gameStateStack.empty()) {
		gameStateStack.pop();
	}
}

StateStack::PendingChange::PendingChange(States::Action action, StatePtr&& add)
: action (action), add(std::move(add))
{
	
}

StatePtr& StateStack::getCurrentState()
{
    assert(!gameStateStack.empty());
    return gameStateStack.top();
}

bool StateStack::empty() const
{
	return gameStateStack.empty();
}

void StateStack::requestAdd(std::unique_ptr<State>&& add)
{
	pendingChanges.emplace_back(PendingChange(States::Add, std::move(add)));
}

void StateStack::requestClear()
{
	pendingChanges.emplace_back(PendingChange(States::Clear));
}

void StateStack::requestPop()
{
	pendingChanges.emplace_back(PendingChange(States::Pop));
}

void StateStack::applyPendingChanges()
{
	for (auto & change : pendingChanges) {
		switch (change.action) {
			case States::Add:
				addState(std::move(change.add));
				break;
				
			case States::Pop:
				popTop();
				break;
				
			case States::Clear:
				clear();
				break;
				
			default:
				break;
		}
	}
	pendingChanges.clear();
}









