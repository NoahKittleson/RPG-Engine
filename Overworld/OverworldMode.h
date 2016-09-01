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
#include "DialogueMode.h"
#include "BattleMode.h"


class OverworldMode: public State
{
public:
	OverworldMode(MapSection* map);
	void update(sf::RenderWindow &rw, sf::Clock&) override;
	void draw(sf::RenderWindow &rw) override;
	std::string handleEvent() override;
	
private:
	void handleMovement(float);
	void handlePlayerCollision(sf::Vector2f);
	void checkExits();
	void checkTriggers(sf::RenderWindow &rw);
	void checkForInteraction(sf::RenderWindow &rw);
	void handleKeyPress(sf::RenderWindow &rw);
	
	void updateView();
	void drawPlayerCollision(sf::RenderWindow &rw);
	void drawAllBoxes(sf::RenderWindow &rw);
	
	void addDialogueState(DNode*, sf::RenderWindow &rw);
	
	sf::View view;
};

template <typename Creation, typename... ParamTypes>
std::unique_ptr<Creation> make_unique(ParamTypes&& ... params)
{
	return std::unique_ptr<Creation>(new Creation(std::forward<ParamTypes>(params)...));
}

//take the ActionPOInt*, determine the type, and create a unique_ptr to a newstate.




