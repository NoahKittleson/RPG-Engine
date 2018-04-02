//
//  BattleEndMode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 4/1/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"

class BattleEndMode : public Mode
{
public:
	BattleEndMode();
	virtual void update(float elapsed) override;
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void handleInput(sf::RenderWindow &rw) override;
	
private:
	sf::RectangleShape screenFade;
	float alpha = 0;
};
