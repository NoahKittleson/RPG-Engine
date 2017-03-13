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
}

void Fade::update(float elapsed) {
    //animate everything that needs to be animated
    //update all lower components
    fadeProgress += elapsed;
}

void Fade::draw(sf::RenderWindow &rw) {
    //draw fade box
    
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
