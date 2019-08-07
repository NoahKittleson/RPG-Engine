//
//  Fade.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/25/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "Fade.hpp"

Fade::Fade(FadeDirection inOrOut, float time) : totalDuration(time) {
    fadeDir = inOrOut;
    jankScreenFade.setSize(sf::Vector2f(2000,2000));
    auto color = sf::Color::Black;
    inOrOut ? color.a = 255 : color.a = 0;
    jankScreenFade.setFillColor(color);
}

Fade::~Fade() {
}

void Fade::update(float elapsed, State* context) {
    fadePercent += elapsed / totalDuration;
    if (fadePercent > 1.0f) {
        fadePercent = 1.0f;
    }
    sf::Color color = jankScreenFade.getFillColor();
    fadeDir == in ? color.a = 255 - 255 * fadePercent : color.a = 255 * fadePercent;
    jankScreenFade.setFillColor(color);
	if ((fadeDir == out && color.a >= 255) || (fadeDir == in && color.a <= 0)) {
		done = true;
	}
}

void Fade::draw(sf::RenderWindow &rw) {
    //draw fade box
	sf::View originalView = rw.getView();
    rw.setView(rw.getDefaultView());
    jankScreenFade.setPosition(0,0);
    rw.draw(jankScreenFade);
	rw.setView(originalView);								//this is a very jank way to preserve the original View
}

void Fade::handleInput(sf::RenderWindow &rw) {
    sf::Event event;
    while (rw.pollEvent(event)) {
        return;
    }
}

//Mode::modeAction Fade::handleEvent() {
//    if (fadePercent >= 1.0) {
//        return inOrOut ? modeAction::FadeInEnd : modeAction::FadeOutEnd;
//    }
//    return modeAction::None;
//}

