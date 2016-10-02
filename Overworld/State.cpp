//
//  StateStack.cpp
//  Overworld
//
//  Created by Noah Kittleson on 11/20/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "State.h"


State::~State()
{
    
}

void State::addToStack(State* addMe)
{
    stack->addState(addMe);
}

void State::addToStackAndBreak(State *addMe)
{
    looping = false;
    stack->addState(addMe);
}

void State::setStack(StateStack &SS)
{
    stack = &SS;
}

bool State::checkDeletion()
{
    return deletionOrder;
}

void State::load() {
    party.emplace_back(500, 450, 75, resources.getTexture("BasicIdle.png"),
                                  resources.getFont("sansation.ttf"), "Pringus", "CLASH", false,
                                  resources.getTexture("GetHitAnimation.png"));
    party.back()._recoveryAbility.setProperties(Ability::Heal, 100);
    Ability ability1 ("BigPunch", "Makes a big punch", 100, false, false,
                      resources.getTexture("BadAttackAnimation.png"));
    ability1.setReq(Ability::ManaCost, 100);
    Ability ability2 ("SmallPunch", "Makes a smaller punch" , 50, false, false,
                      resources.getTexture("BadAttackAnimation.png"));
    ability2.setReq(Ability::ManaCost, 50);
    party.back().addAbility(ability1);
    party.back().addAbility(ability2);
}

const ResourceHolder State::resources;
StateStack* State::stack;
MapSection* State::currentMap;
std::vector<Character> State::party;
Player State::playerSprite;
