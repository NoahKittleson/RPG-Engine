//
//  MenuMode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"

class MenuMode: public Mode
{
public:
	virtual void update(float elapsed) override;
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void handleInput(sf::RenderWindow &rw) override;
	
private:
	menuTree menu;
	
	
}
