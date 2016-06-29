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

class StateStack
{
public:
    ~StateStack();
    
    void popTop();
    void addState(State*);
    //void addDialogue(DialogueThread* thread);
    //void addBattle(std::list<Character> enemies);
    //void addOverworld(MapSection*);
    
    State* getCurrentState();
    
private:
    std::stack<State*> gameStateStack;
    
};