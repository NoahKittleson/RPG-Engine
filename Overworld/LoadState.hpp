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
#include "MapFactory.hpp"
#include "CharacterGenerator.hpp"
#include <fstream>

class LoadState: public State
{
public:
    LoadState(StateStack& stack);
	void handleInput(sf::RenderWindow& rw) override;
    void update(sf::Clock&) override;
    void draw(sf::RenderWindow&) override;
	
	void load();
	void loadFromDisc(std::string filename, std::map<std::string, Condition>& conditionAtlas);
	void save(const std::string& filename);
};
