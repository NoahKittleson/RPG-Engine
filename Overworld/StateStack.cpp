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

void StateStack::addState(StatePtr addMe)
{
    if (addMe) {
        gameStateStack.push(addMe);
    }
}

StatePtr& StateStack::getCurrentState()
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
