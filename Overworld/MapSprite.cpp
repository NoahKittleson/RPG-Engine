//
//  MapSprite.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "MapSprite.hpp"

int MapSprite::getBase() const {
    return getPosition().y + (getTextureRect().height * getScale().y) - (getOrigin().y * getScale().y);
}

void MapSprite::drawBase(sf::RenderWindow &rw) {
    sf::RectangleShape rect (sf::Vector2f(20, 1));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(getPosition().x, getBase());
    rw.draw(rect);
}

void MapSprite::update(float elapsed) {
    if (timePerFrame > 0) {
        animate(elapsed);
    }
}

void MapSprite::animate(float elapsed) {
    totalElapsed+= elapsed;
    while (totalElapsed >= timePerFrame) {
        totalElapsed -= timePerFrame;
        nextFrame();
        
    }
}

void MapSprite::nextFrame() {
    if (getTextureRect().left + frameSize.width >= getTexture()->getSize().x) {
        setTextureRect(frameSize);
    }
    else setTextureRect(sf::IntRect(getTextureRect().left + frameSize.width,
                                    getTextureRect().top,
                                    getTextureRect().width,
                                    getTextureRect().height ));
}
