//
//  Fade.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/25/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "Fade.hpp"

Fade::Fade(bool inOut) {
    inOrOut = inOut;
    jankScreenFade.setSize(sf::Vector2f(2000,2000));
    jankScreenFade.setFillColor(sf::Color::Black);
}

void Fade::update(float elapsed) {
    fadeProgress += elapsed;
}

void Fade::draw(sf::RenderWindow &rw) {
    //draw fade box
    rw.setView(rw.getDefaultView());
    rw.draw(jankScreenFade);
}

void Fade::handleInput(sf::RenderWindow &rw, float elapsed) {
    //nothing
}

Mode::modeAction Fade::handleEvent() {
    if (fadeProgress > 1.0) {
        return inOrOut ? modeAction::FadeInEnd : modeAction::FadeOutEnd;
    }
    return modeAction::None;
}
