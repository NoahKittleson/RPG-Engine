//
//  MainMenuState.hpp
//  Overworld
//
//  Created by Noah Kittleson on 10/29/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "State.h"
#include "Menu.hpp"
#include "OverworldMode.h"

class MainMenuState : public State {
public:
	MainMenuState();
	void update(sf::Clock&) override;
	void draw(sf::RenderWindow&) override;
	void handleInput(sf::RenderWindow&) override;

private:
	sf::Sprite background;
	std::shared_ptr<Menu> mainMenu;
	std::vector<Command> commandVec;
};
