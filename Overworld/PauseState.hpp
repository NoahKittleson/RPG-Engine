//
//  PauseState.hpp
//  Overworld
//
//  Created by Noah Kittleson on 6/29/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "State.h"

class PauseState : public State {
public:
	PauseState(sf::RenderWindow& rw);
	void update(sf::Clock&) override;
	void draw(sf::RenderWindow&) override;
	void handleInput(sf::RenderWindow&) override;
	
private:
	sf::Text pausedText;
	sf::RectangleShape rect;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	
};
