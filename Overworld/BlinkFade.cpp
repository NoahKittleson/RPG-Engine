//
//  BlinkFade.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/22/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "BlinkFade.hpp"


BlinkFade::BlinkFade(FadeDirection inOrOut, float duration) : Fade(inOrOut, duration) {

}

void BlinkFade::update(float elapsed, State* context) {
	blinkTimer += elapsed;
	fadePercent += elapsed/totalDuration;
	sf::Color color = jankScreenFade.getFillColor();
	float changeAmount = 200*elapsed/blinkLength;					//magic number
	if (fadeToBlack && changeAmount + color.a < 255) {
		color.a += changeAmount;
	} else if (!fadeToBlack && changeAmount < color.a) {
		color.a -= changeAmount;
	}
	jankScreenFade.setFillColor(color);
	if (blinkTimer > blinkLength) {
		fadeToBlack = !fadeToBlack;
		blinkTimer = 0;
	}
	if (fadePercent > 1.0f) {
		done = true;
		fadePercent = 1.0f;
	}
}
