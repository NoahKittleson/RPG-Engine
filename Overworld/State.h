//
//  StateStack.h
//  Overworld
//
//  Created by Noah Kittleson on 11/20/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "StateStack.h"
#include "MapSection.h"
#include "ResourceHolder.h"
//#include "SaveInfo.h"

class StateStack;

class State
{
public:
    virtual ~State();
    virtual void update(sf::RenderWindow&, sf::Clock&) = 0;
    virtual void draw(sf::RenderWindow&) = 0;
    virtual void handleEvent() = 0;

    void addToStack(State*);
    void addToStackAndBreak(State*);
    bool checkDeletion();
    void setStack(StateStack&);
    
protected:
    //this is effectively functioning as the gameInfo class I had considered
    //I need a way to make sure this is all initialized as correct values the first time I call ANY of the states.
    //perhaps a LOADSTATE which exists to fill ResourceHolder, currentMap, party, and playerSprite with correct values.
    
    static MapSection* currentMap;
    static std::list<Character> party;
    static Player playerSprite;               //do I need this? Will this be stored in first Character?
    //const static ResourceHolder resources;

    bool deletionOrder = false;
    bool looping = true;
private:
    static StateStack* stack;

};