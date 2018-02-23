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
#include "MapSection.h"
#include "BigField.hpp"
#include "StartingZone.h"
#include "DialogueMode.h"
#include "BattleState.h"
#include "Fade.hpp"


class OverworldMode: public State
{
public:
	OverworldMode();
	void handleInput(sf::RenderWindow& rw) override;
	void update(sf::Clock&) override;
	void draw(sf::RenderWindow &rw) override;
	
private:
	void handleMovement(float elapsed);
	void checkExits();
	void changeMap(ZoneExit);
	void checkTriggers();
	void checkForInteraction(sf::RenderWindow &rw);
	void handleInput(sf::RenderWindow &rw, float elapsed);
	
	void updateView();
	void drawPlayerCollision(sf::RenderWindow &rw);
	void drawAllBoxes(sf::RenderWindow &rw);
	
	
	sf::View view;
	std::unique_ptr<Mode> mode;
	//if Commands get complicated, make them their own class, rather than just an enum
	enum Command {Left, Right, Up, Down, X, Z};
	std::vector<Command> CommandQueue;
};



