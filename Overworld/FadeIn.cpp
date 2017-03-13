//
//  FadeIn.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/25/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "FadeIn.hpp"

void FadeIn::update(float elapsed) {
    //animate everything that needs to be animated
    //update all lower components
    fadeProgress += elapsed;
    //handle input
    
}

void FadeIn::draw(sf::RenderWindow &rw) {
    //draw fade box
    
}

void FadeIn::handleInput(sf::RenderWindow &rw, float elapsed) {
    //nothing
}

Mode::modeAction FadeIn::handleEvent() {
    if (fadeProgress > 1.0) {
        return modeAction::FadeInEnd;
    }
    return modeAction::None;
}
