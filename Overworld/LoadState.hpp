//
//  LoadState.hpp
//  Overworld
//
//  Created by Noah Kittleson on 2/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//
#pragma once
#include "State.h"
#include "WalkingAnimation.hpp"
#include "StartingZone.h"
#include "CharacterGenerator.hpp"

class LoadState: public State
{
public:
    LoadState(StateStack& stack);
	void handleInput(sf::RenderWindow& rw) override;
    void update(sf::Clock&) override;
    void draw(sf::RenderWindow&) override;
};
