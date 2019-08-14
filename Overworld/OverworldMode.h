//
//  OverworldMode.h
//  Overworld
//
//  Created by Noah Kittleson on 4/22/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//


#pragma once
#include "PrefixHeader.pch"
#include "State.h"
#include "DialogueMode.h"
#include "BattleState.h"
#include "Fade.hpp"
#include "MapFactory.hpp"
#include "BlinkFade.hpp"
#include "PauseState.hpp"
#include "SafeStack.hpp"


#include <thread>


class OverworldMode: public State
{
public:
	OverworldMode();
	void handleInput(sf::RenderWindow& rw) override;
	void update(sf::Clock&) override;
	void draw(sf::RenderWindow &rw) override;
	
private:
	bool handleMovement(float elapsed);				//return true if movement occurs
	void handleOOB() const;
	int checkExits();								//returns index of intersected exit, or -1 if none intersect
	void changeMap(ZoneExit);
	void checkTriggers();
	void checkForInteraction(sf::RenderWindow &rw);
	
	void updateView();
	void drawPlayerCollision(sf::RenderWindow &rw);
	void drawAllBoxes(sf::RenderWindow &rw);
	
	sf::View view;
	SafeStack<Mode> activePhase;
	
	//if Commands get complicated, make them their own class, rather than just an enum
	enum Command {Left, Right, Up, Down, X, Z};
	std::vector<Command> CommandQueue;
	
	bool debugMode = false;
	bool fadePlayed = false;
};



