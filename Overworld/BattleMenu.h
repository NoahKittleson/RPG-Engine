//
//  BattleMenu.h
//  SFML test
//
//  Created by Noah Kittleson on 1/12/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"


class Character;
class Ability;

struct BattleAction {
	Character* attacker = nullptr;
	std::vector<Character*> defenders;
	Ability* ability = nullptr;
};

class BattleMenu : public Mode
{
public:
	virtual void update(float elapsed);
	virtual void draw(sf::RenderWindow &rw);
	virtual void handleInput(sf::RenderWindow &rw);
	virtual modeAction handleEvent() { return modeAction::None; };			//this is unused and should be redone
private:
	BattleAction action;
};


