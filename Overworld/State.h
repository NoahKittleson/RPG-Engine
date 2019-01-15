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
#include "AudioHandler.hpp"

//#include "SaveInfo.h"

class StateStack;
class Mode;

class State
{
	using StatePtr = std::unique_ptr<State>;
	
public:
    virtual ~State();
    virtual void update(sf::Clock&) = 0;
    virtual void draw(sf::RenderWindow&) = 0;
	virtual void handleInput(sf::RenderWindow&) = 0;

	//can I get this to be not public?  I want to have some encapsulation here.
	static AudioHandler audioPlayer;

	
protected:
    //this is effectively functioning as the gameInfo class I had considered 
	static std::unique_ptr<MapSection> currentMap;
	static std::vector<std::shared_ptr<Character>> party;
	static std::unique_ptr<PlayerObject> player;
    const static ResourceHolder resources;
	static StateStack* stack;
    static std::vector<Condition> conditions;
    //sf::Music musicPlayer;
	void requestStackAdd(std::unique_ptr<State>&&);
	void requestStackPop();
	void requestStateClear();
};


//Things to do:
//1.Create GameInfo class for map, party, player, others?
//2.Give ability to save game


