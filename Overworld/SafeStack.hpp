//
//  SafeStack.hpp
//  Overworld
//
//  Created by Noah Kittleson on 8/7/19.
//  Copyright © 2019 Noah. All rights reserved.
//

#include "PrefixHeader.pch"
//#include "StateStack.h"
#include "PendingChange.hpp"


//this is just a templated version of StateStack, to use for modes.  Also uses a queue instead of stack.  Stupid name.
//If this is actually useful then actually make it not stupid.

template <typename T>
class SafeStack
{
public:
	~SafeStack();
	
	bool empty() const;
	std::unique_ptr<T>& getCurrentT();
	
	void requestAdd(std::unique_ptr<T>&& add);
	void requestClear();
	void requestPop();
	void applyPendingChanges();
	
private:
	struct PendingChange
	{
		explicit PendingChange(States::MyAction action, std::unique_ptr<T>&& add = nullptr);
		
		States::MyAction action;
		std::unique_ptr<T> add;
	};
	
private:
	void addT(std::unique_ptr<T>&&);
	void clear();
	void popTop();
	
	std::stack<std::unique_ptr<T>> objectStack;
	std::vector<PendingChange> pendingChanges;
};




#include "SafeStack.inl"

