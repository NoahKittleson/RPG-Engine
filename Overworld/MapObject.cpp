//
//  MapObject.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "MapObject.hpp"

MapObject::MapObject(GraphicsComponent* gc, RectVec collision)
: graphics(gc), collisionBoxes(collision)
{

}

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

void MapObject::collideX(MapObject &PC, sf::Vector2f moveVec) {
	
	for (auto const & ourBox : collisionBoxes) {
		for (auto const & theirBox : PC.collisionBoxes) {
			if (theirBox.intersects(ourBox)) {
				if (moveVec.x > 0) {			//moving right
					PC.setPosition(ourBox.left - theirBox.width/2, PC.getPosition().y);
				}
				else if (moveVec.x < 0) {		//moving left
					PC.setPosition(ourBox.left + ourBox.width + theirBox.width/2, PC.getPosition().y);
				}
			}
		}
	}
}

void MapObject::collideY(MapObject &PC, sf::Vector2f moveVec) {
	
	for (auto const & ourBox : collisionBoxes) {
		for (auto const & theirBox : PC.collisionBoxes) {
			if (theirBox.intersects(ourBox)) {
				if (moveVec.y > 0) {			//moving down
					PC.setPosition(PC.getPosition().x, ourBox.top - theirBox.height/2);
				}
				else if (moveVec.y < 0){		//moving up
					PC.setPosition(PC.getPosition().x, ourBox.top + ourBox.height + theirBox.height/2);
				}
			}
		}
	}
}


