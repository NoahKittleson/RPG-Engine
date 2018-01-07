//
//  MenuNode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MenuNode.hpp"

class MenuItem : public MenuNode {
public:
	virtual void draw(sf::RenderWindow &rw) override;
	virtual void update(float elapsed) override;
	virtual void handleInput(sf::RenderWindow& rw) override;
	virtual void select() override;						//select is for highlighting current option, activate for executing it
	virtual void activate() override;
	virtual void deselect() override;
	virtual void deactivate() override;
	virtual bool selectable() override;
	
private:
	//action to be taken when selected
	
}
