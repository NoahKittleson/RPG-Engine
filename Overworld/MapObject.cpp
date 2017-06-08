//
//  MapObject.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "MapObject.hpp"

MapObject::MapObject(GraphicsComponent* gc, RectVec collision)
: graphics(gc)
{
	sf::Vector2f position = gc->getPosition();
	for (auto && box : collision) {
		collisionBoxes.push_back(sf::FloatRect(position.x + box.left, position.y + box.top, box.width, box.height));
	}
}

MapObject::~MapObject() {
	//consider having non-dynamic componenets if I want to double up on multiple objects with same graphics
	delete graphics;
	std::cout << "graphics deleted\n";
}

MapObject::MapObject(const MapObject& obj) {
	this->graphics = new GraphicsComponent(*obj.graphics);
}


void MapObject::update(float elapsed) {
	//input->update();
	//collision...?
	graphics->update(*this, elapsed);
	//in future, graphics will need to update based on movement IF WalkingAnimation component is in play
}

void MapObject::setPosition(float x, float y) {
	auto position = graphics->getPosition();
	graphics->setPosition(x, y);

	for (auto & box : collisionBoxes) {
		sf::Vector2f offset = sf::Vector2f(box.left - position.x, box.top - position.y);
		box.left = x + offset.x;
		box.top = y + offset.y;
	}
}

sf::Vector2f MapObject::getPosition() {
    return graphics->getPosition();
}

void MapObject::draw(sf::RenderWindow &rw) const {
	rw.draw(*graphics);
}

void MapObject::move(float x, float y) {
	auto position = graphics->getPosition();
	graphics->move(x, y);
	for (auto & box : collisionBoxes) {
		sf::Vector2f offset = sf::Vector2f(box.left - position.x, box.top - position.y);
		box.left = graphics->getPosition().x + offset.x;
		box.top = graphics->getPosition().y + offset.y;
	}
}

void MapObject::move(sf::Vector2f xy){
	move(xy.x, xy.y);
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

void MapObject::drawCenter(sf::RenderWindow &rw) const{
	sf::RectangleShape rect (sf::Vector2f(1,1));
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(graphics->getPosition().x,
					 graphics->getPosition().y);
	//std::cout << "drawing center at: " << graphics->getPosition().x << ", " << graphics->getPosition().y << "\n";
}

void MapObject::drawCollision(sf::RenderWindow& rw) {
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Red);
	for (auto const & it: collisionBoxes) {
		rectangle.setSize(sf::Vector2f(it.width, it.height));
		rectangle.setPosition(it.left, it.top);
		rw.draw(rectangle);
	}
}

void MapObject::addTime(float delta) {
	graphics->addTime(delta);
}

void MapObject::setScale(float scale) {
	graphics->setScale(scale, scale);
}

void MapObject::collideX(MapObject &PC, float x) const {
	
	for (auto const & ourBox : collisionBoxes) {
		for (auto const & theirBox : PC.collisionBoxes) {
			if (theirBox.intersects(ourBox)) {
				if (x > 0) {			//moving right
					PC.setPosition(ourBox.left - theirBox.width/2, PC.getPosition().y);
				}
				else if (x < 0) {		//moving left
					PC.setPosition(ourBox.left + ourBox.width + theirBox.width/2, PC.getPosition().y);
				}
			}
		}
	}
}

void MapObject::collideY(MapObject &PC, float y) const {
	
	for (auto const & ourBox : collisionBoxes) {
		for (auto const & theirBox : PC.collisionBoxes) {
			if (theirBox.intersects(ourBox)) {
				if (y > 0) {			//moving down
					PC.setPosition(PC.getPosition().x, ourBox.top - theirBox.height/2);
				}
				else if (y < 0){		//moving up
					PC.setPosition(PC.getPosition().x, ourBox.top + ourBox.height + theirBox.height/2);
				}
			}
		}
	}
}

bool MapObject::intersects(sf::FloatRect box) {
	for (auto && it : collisionBoxes) {
		if (it.intersects(box)) {
			return true;
		}
	}
	return false;
}

DNode* MapObject::getDNode() const {
	//return dialogue;
	
	//disabled for now, because I have yet to design DialogueComponent
	return nullptr;
}



