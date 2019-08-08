//
//  ModeHandler.hpp
//  Overworld
//
//  Created by Noah Kittleson on 8/7/19.
//  Copyright © 2019 Noah. All rights reserved.
//


//this is a copy and pasted version of StateStack.  If this ends up being useful, replace with a templated version of StateStack (same for the original StateStack)

#pragma once
#include "Mode.cpp"
#include <queue>

class Mode;
using ModePtr = std::unique_ptr<Mode>;

namespace Modes {
	enum Action
	{
		Add,
		Pop,
		Clear,
	};
}


class ModeStack
{
public:
	~ModeStack();
	
	bool empty() const;
	ModePtr& getCurrentMode();
	
	void requestAdd(std::unique_ptr<Mode>&& add);
	void requestClear();
	void requestPop();
	void applyPendingChanges();
	
private:
	struct PendingChange
	{
		explicit PendingChange(Modes::Action action, ModePtr&& add = nullptr);
		
		Modes::Action action;
		ModePtr add;
	};
	
private:
	void addMode(ModePtr&&);
	void clear();
	void popTop();
	
	std::stack<ModePtr> gameModeStack;
	std::vector<PendingChange> pendingChanges;
};

