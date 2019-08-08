//
//  ModeStack.cpp
//  Overworld
//
//  Created by Noah Kittleson on 11/21/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "ModeHandler.hpp"

ModeStack::~ModeStack()
{
	
}

void ModeStack::popTop()
{
	gameModeStack.pop();
}

void ModeStack::addMode(ModePtr&& addMe)
{
	if (addMe) {
		gameModeStack.push(std::move(addMe));
	}
}

void ModeStack::clear()
{
	while (!gameModeStack.empty()) {
		gameModeStack.pop();
	}
}

ModeStack::PendingChange::PendingChange(Modes::Action action, ModePtr&& add)
: action (action), add(std::move(add))
{
	
}

ModePtr& ModeStack::getCurrentMode()
{
	assert(!gameModeStack.empty());
	return gameModeStack.top();
}

bool ModeStack::empty() const
{
	return gameModeStack.empty();
}

void ModeStack::requestAdd(std::unique_ptr<Mode>&& add)
{
	pendingChanges.emplace_back(PendingChange(Modes::Add, std::move(add)));
}

void ModeStack::requestClear()
{
	pendingChanges.emplace_back(PendingChange(Modes::Clear));
}

void ModeStack::requestPop()
{
	pendingChanges.emplace_back(PendingChange(Modes::Pop));
}

void ModeStack::applyPendingChanges()
{
	for (auto & change : pendingChanges) {
		switch (change.action) {
			case Modes::Add:
				addMode(std::move(change.add));
				break;
				
			case Modes::Pop:
				popTop();
				break;
				
			case Modes::Clear:
				clear();
				break;
				
			default:
				break;
		}
	}
	pendingChanges.clear();
}










