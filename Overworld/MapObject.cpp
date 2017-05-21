//
//  MapObject.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "MapObject.hpp"


void MapObject::setPosition(float x, float y) {
    graphics->setPosition(x, y);
}

sf::Vector2f MapObject::getPosition() {
    return graphics->getPosition();
}

int MapObject::getBase() const {
    return graphics->getPosition().y + (graphics->getTextureRect().height * graphics->getScale().y) -(graphics->getOrigin().y * graphics->getScale().y);
}

void MapObject::drawBase(sf::RenderWindow &rw) const {
    sf::RectangleShape rect (sf::Vector2f(20, 1));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(graphics->getPosition().x, getBase());
    rw.draw(rect);
}

void MapObject::addTime(float delta) {
	graphics->addTime(delta);
}
