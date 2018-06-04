//
//  MapObject.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "MapObject.hpp"

MapObject::MapObject(graphicsPtr&& gc, const RectVec& collision)
: graphics(std::move(gc))
{
	sf::Vector2f position = graphics->getPosition();
	for (auto && box : collision) {
		collisionBoxes.push_back(sf::FloatRect(position.x + box.left, position.y + box.top, box.width, box.height));
	}
}

MapObject::~MapObject() {
	std::cout << "MapObject deleted\n";
}

MapObject::MapObject(const MapObject& obj) {
	this->graphics = obj.graphics->getCopy();
	sf::Vector2f position = graphics->getPosition();
	for (auto & box : obj.collisionBoxes) {
		collisionBoxes.push_back(sf::FloatRect(position.x + box.left, position.y + box.top, box.width, box.height));
	}
	std::cout << "collision other:" << obj.collisionBoxes.size() << "\n";
	std::cout << "collision:" << collisionBoxes.size() << "\n";

}


void MapObject::update(float elapsed) {
	//input->update();
	//collision...?
	graphics->update(elapsed);
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
	return graphics->getBase();
}

void MapObject::offsetBase(float x) {
	graphics->offsetBase(x);
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
}

void MapObject::drawCollision(sf::RenderWindow& rw) const {
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color(255,0,0,50));				//partially opaque red
	for (auto const & it: collisionBoxes) {
		rectangle.setSize(sf::Vector2f(it.width, it.height));
		rectangle.setPosition(it.left, it.top);
		rw.draw(rectangle);
//		std::cout << "collision:" << it.left << ", " << it.top << ", " << it.width << ", " << it.height << "\n";
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
					auto offsetX = PC.getPosition().x - (theirBox.left + theirBox.width);
					PC.setPosition(ourBox.left + offsetX, PC.getPosition().y);
				}
				else if (x < 0) {		//moving left
					auto offsetX = PC.getPosition().x - theirBox.left;
					PC.setPosition(ourBox.left + ourBox.width + offsetX, PC.getPosition().y);
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
					auto offsetY = PC.getPosition().y - (theirBox.top + theirBox.height);
					PC.setPosition(PC.getPosition().x, ourBox.top + offsetY);
				}
				else if (y < 0){		//moving up
					auto offsetY = PC.getPosition().y - theirBox.top;
					PC.setPosition(PC.getPosition().x, ourBox.top + ourBox.height + offsetY);
				}
			}
		}
	}
}

bool MapObject::intersects(sf::FloatRect box) const {
	for (auto && it : collisionBoxes) {
		if (it.intersects(box)) {
			return true;
		}
	}
	return false;
}

NodePtr MapObject::getDNode() const {
	return dialogue;
}

void MapObject::attachDialogue(NodePtr toAdd) {
	dialogue = toAdd;
}




