//
//  BattleMenu.h
//  SFML test
//
//  Created by Noah Kittleson on 1/12/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"
#include "BattleAction.hpp"

class BattleMenu : public Mode
{
public:
	virtual void update(float elapsed) override;
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void handleInput(sf::RenderWindow &rw) override;
	virtual modeAction handleEvent() override { return modeAction::None; };			//this is unused and should be redone

private:
	BattleAction action;
};


