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


class OverworldMode: public State
{
public:
	OverworldMode();
	void update(sf::RenderWindow &rw, sf::Clock&) override;
	void draw(sf::RenderWindow &rw) override;
	ActionID handleEvent() override;
	
private:
	//temporary?
	float fadeProgress = 0.f;
	
	enum State {FadeIn, FadeOut, Dialogue, Normal};
	State overWorldState;
	
	void handleMovement(float elapsed, sf::Vector2f moveVec);
	void handlePlayerCollision(sf::Vector2f);
	void checkExits();
	ActionID checkTriggers();
	void checkForInteraction(sf::RenderWindow &rw);
	//is there a better way to do this without overcomplicating things?
	void handleInput(sf::RenderWindow &rw, float elapsed);
	void handleInputFade(sf::RenderWindow &rw, float elapsed);
	void handleInputDialogue(sf::RenderWindow &rw, float elapsed);
	
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




