//
//  BattleState.h
//  Overworld
//
//  Created by Noah Kittleson on 12/31/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "State.h"
#include "Mode.hpp"
#include "MenuMode.hpp"
#include "AttackMode.hpp"
#include "BattleInfo.hpp"

class BattleState : public State
{
public:
	BattleState(std::vector<std::shared_ptr<Character>>& enemies);
	void update(sf::Clock& timer) override;
	void draw(sf::RenderWindow&) override;
	void handleInput(sf::RenderWindow& rw) override;
	
private:
	std::unique_ptr<Mode> mode;
	enum ModeType {menu, attack};
	ModeType currentMode = menu;
	BattleInfo info;
	void loadMenu();
	void drawAll(sf::RenderWindow &rw);
	void positionSpritesAndStats();
	
};


