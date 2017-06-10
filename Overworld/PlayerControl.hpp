//
//  PlayerControl.hpp
//  Overworld
//
//  Created by Noah Kittleson on 6/9/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "InputComponent.hpp"

using Key = sf::Keyboard::Key;

class PlayerControl : public InputComponent
{
public:
	PlayerControl(WalkingAnimation* spr, Key up, Key down, Key left, Key right);
	virtual void update(sf::RenderWindow& rw, float elapsed) override;
	
private:
	virtual void updateSprite(WalkingAnimation* spr);	//this isn't really going to be a thing

	Key up;
	Key down;
	Key left;
	Key right;
};

