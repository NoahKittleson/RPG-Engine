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

class State;
using StatePtr = std::unique_ptr<State>;


class StateStack
{
public:
    ~StateStack();
    
    void popTop();
    void addState(StatePtr);
    //void addDialogue(DialogueThread* thread);
    //void addBattle(std::list<Character> enemies);
    //void addOverworld(MapSection*);
    
	StatePtr& getCurrentState();
    
private:
    std::stack<StatePtr> gameStateStack;
    
};
