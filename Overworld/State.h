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
    State();
    virtual void update(sf::RenderWindow&, sf::Clock&) = 0;
    virtual void draw(sf::RenderWindow&) = 0;
    virtual ActionID handleEvent() = 0;

    void addToStack(State*);
    bool checkDeletion();
    
    void load();    //this is a very janky version of how this will eventually work
    
protected:
    //this is effectively functioning as the gameInfo class I had considered
    //I need a way to make sure this is all initialized as correct values the first time I call ANY of the states.
    //perhaps a LOADSTATE which exists to fill ResourceHolder, currentMap, party, and playerSprite with correct values.    
    static MapSection* currentMap;
    static std::vector<Character> party;
    static Player* playerSprite;               //consider boost_ptr unique pointer?
    const static ResourceHolder resources;
    static std::vector<Condition> conditions;
    sf::Music musicPlayer;
    
    bool deletionOrder = false;
    
    static StateStack* stack;
private:
    int instances = 0;

};


//Things to do:
//1.Create LoadState for initialization of values
//2.Create GameInfo class for map, party, player, others?
//3.Give ability to save game


