//
//  BlinkFade.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/22/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BlinkFade.hpp"


BlinkFade::BlinkFade(bool inOut, float duration) : Fade(inOut, duration) {
	
}

void BlinkFade::update(float elapsed) {
	blinkTimer += elapsed;
	fadePercent += elapsed/totalDuration;
	if (blinkTimer > .25) {									//magic number
		solidBlack = !solidBlack;
		blinkTimer = 0;
		sf::Color color = jankScreenFade.getFillColor();
		solidBlack ? color.a = 255 - 255 : color.a = 255;
		jankScreenFade.setFillColor(color);
	}
	if (fadePercent > 1.0f) {
		done = true;
		fadePercent = 1.0f;
	}
}
