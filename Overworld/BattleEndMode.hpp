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
	BattleEndMode(bool victory, const sf::Font& font);
	virtual void update(float elapsed, State* context) override;
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void handleInput(sf::RenderWindow &rw) override;
	
private:
	bool victory;
	sf::RectangleShape screenFade;
	float alpha = 0;
	sf::Text youDied;
	float lingerTime = 1.f;			//kinda magic number...
};
