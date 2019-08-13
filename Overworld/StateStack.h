//
//  StateStack.h
//  Overworld
//
//  Created by Noah Kittleson on 11/21/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "State.h"
#include <stack>
#include "PendingChange.hpp"

class State;
using StatePtr = std::unique_ptr<State>;

class StateStack
{
public:
    ~StateStack();

	bool empty() const;
	StatePtr& getCurrentState();
	
	void requestAdd(std::unique_ptr<State>&& add);
	void requestClear();
	void requestPop();
	void applyPendingChanges();
	
private:
	struct PendingChange
	{
		explicit PendingChange(States::MyAction action, StatePtr&& add = nullptr);
		
		States::MyAction action;
		StatePtr add;
	};
	
private:
	void addState(StatePtr&&);
	void clear();
	void popTop();
	
    std::stack<StatePtr> gameStateStack;
	std::vector<PendingChange> pendingChanges;
};
