//
//  Fade.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/25/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "Fade.hpp"

Fade::Fade(bool inOut, float time) : totalDuration(time) {
    inOrOut = inOut;
    jankScreenFade.setSize(sf::Vector2f(2000,2000));
    std::cout << "Fade Created\n";
}

void Fade::update(float elapsed) {
    fadeProgress += elapsed;
    sf::Color color  = inOrOut ? sf::Color(0, 0, 0, 255 - 255 * fadeProgress) : sf::Color(0, 0, 0, 255 * fadeProgress);
    jankScreenFade.setFillColor(color);
}

void Fade::draw(sf::RenderWindow &rw) {
    //draw fade box
    rw.setView(rw.getDefaultView());
    jankScreenFade.setPosition(0,0);
    rw.draw(jankScreenFade);
//    jankScreenFade.getFillColor()
}

void Fade::handleInput(sf::RenderWindow &rw, float elapsed) {
    sf::Event event;
    while (rw.pollEvent(event)) {
        return;
    }
}

Mode::modeAction Fade::handleEvent() {
    if (fadeProgress > totalDuration) {
        return inOrOut ? modeAction::FadeInEnd : modeAction::FadeOutEnd;
    }
    return modeAction::None;
}
