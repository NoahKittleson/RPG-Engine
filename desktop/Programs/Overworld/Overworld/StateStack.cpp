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
    for (auto && it: gameStateStack) {
        delete it;
    }
}

void StateStack::popFront()
{
    delete *gameStateStack.begin();
    gameStateStack.pop_front();
}

void StateStack::addState(State *addMe)
{
    gameStateStack.push_front(addMe);               //this is dynamically allocated memory.
}

State* StateStack::getCurrentState()
{
    assert(!gameStateStack.empty());
    return *gameStateStack.begin();
}

//void StateStack::addDialogue(DialogueThread* thread)
//{
//    DialogueMode* addMe = new DialogueMode (thread);
//    gameStateStack.push_front(addMe);
//}

//void StateStack::addOverworld(MapSection* map)
//{
//    OverworldMode* addMe = new OverworldMode (map);
//    gameStateStack.push_front(addMe);
//}

//void StateStack::addBattle(std::list<Character> enemies)
//{
//    BattleMenu* addMe = new BattleMenu(enemies);
//    gameStateStack.push_front(addMe);
//}