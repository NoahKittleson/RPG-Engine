//
//  BlinkFade.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/22/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "Fade.hpp"

class BlinkFade : public Fade
{
	BlinkFade(bool inOut, float duration);
	void update(float elapsed) override;
	void draw(sf::RenderWindow &rw) override;
	void handleInput(sf::RenderWindow &rw) override;
};
