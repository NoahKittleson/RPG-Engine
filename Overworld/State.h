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
#include "PlayerObject.hpp"
//#include "SaveInfo.h"

class StateStack;

class State
{
	using StatePtr = std::unique_ptr<State>;
	
public:
    virtual ~State();
    virtual void update(sf::RenderWindow&, sf::Clock&) = 0;
    virtual void draw(sf::RenderWindow&) = 0;
    virtual ActionID handleEvent() = 0;

	
	
protected:
    //this is effectively functioning as the gameInfo class I had considered 
	static std::unique_ptr<MapSection> currentMap;
    static std::vector<Character> party;
	static std::unique_ptr<PlayerObject> player;
    const static ResourceHolder resources;
	static StateStack* stack;
    static std::vector<Condition> conditions;
    sf::Music musicPlayer;
    
	void requestStackAdd(std::unique_ptr<State>&&);
	void requestStackPop();
	void requestStateClear();
};

template <typename Creation, typename... ParamTypes>
std::unique_ptr<Creation> make_unique(ParamTypes&& ... params)
{
	return std::unique_ptr<Creation>(new Creation(std::forward<ParamTypes>(params)...));
}


//Things to do:
//1.Create LoadState for initialization of values
//2.Create GameInfo class for map, party, player, others?
//3.Give ability to save game


