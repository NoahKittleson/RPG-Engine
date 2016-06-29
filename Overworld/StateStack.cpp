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
        delete gameStateStack.top();
    }
}

void StateStack::popTop()
{
    delete gameStateStack.top();
    gameStateStack.pop();
}

void StateStack::addState(State *addMe)
{
    if (addMe) {
        gameStateStack.push(addMe);
    }
}

State* StateStack::getCurrentState()
{
    assert(!gameStateStack.empty());
    return gameStateStack.top();
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