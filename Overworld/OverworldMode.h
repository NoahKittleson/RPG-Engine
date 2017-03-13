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
#include "BattleMode.h"
#include "Fade.hpp"


class OverworldMode: public State
{
public:
	OverworldMode();
	void update(sf::RenderWindow &rw, sf::Clock&) override;
	void draw(sf::RenderWindow &rw) override;
	ActionID handleEvent() override;
	
private:
	void handleMovement(float elapsed, sf::Vector2f moveVec);
	void handlePlayerCollision(sf::Vector2f);
	void checkExits();
	ActionID checkTriggers();
	void checkForInteraction(sf::RenderWindow &rw);
	void handleInput(sf::RenderWindow &rw, float elapsed);
	
	void updateView();
	void drawPlayerCollision(sf::RenderWindow &rw);
	void drawAllBoxes(sf::RenderWindow &rw);
	
	void addDialogueState(DNode*, sf::RenderWindow &rw);
	
	sf::View view;
	Mode* mode;
	
};

template <typename Creation, typename... ParamTypes>
std::unique_ptr<Creation> make_unique(ParamTypes&& ... params)
{
	return std::unique_ptr<Creation>(new Creation(std::forward<ParamTypes>(params)...));
}



