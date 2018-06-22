//
//  MapSection.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/4/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "MapSection.h"


MapSection::MapSection(MapID id, std::string musicFile) : ID(id), musicFilename(musicFile) {
	//should this be empty?
};


void MapSection::addObject(MapObject& add)
{
	for (auto it = sprites.begin(); it != sprites.end(); it++) {
		if (add.getBase() < (*it)->getBase()) {
			sprites.emplace(it, std::unique_ptr<MapObject>(new MapObject (add)));
			return;
		}
	}
	sprites.emplace_back(std::unique_ptr<MapObject>(new MapObject (add)));
}

void MapSection::drawBackground(sf::RenderWindow&rw) {
	rw.draw(background);
}

std::string MapSection::getMusicAddress() {
	return resourcePath() + musicFilename;
}

void MapSection::drawAllObjects(sf::RenderWindow &rw, MapObject& player) {
	bool playerDrawn = false;
	bool playerInWater = false;
	for (const auto & zone : waterZones) {
		if (player.intersects(zone)) {
			playerInWater = true;
			break;
		}
	}
	
	if (waterZones.size() && playerInWater) {
		player.drawCropped(0, -7, rw);				//cropping 3 pixels from bottom
	}
	
	for (const auto & obj: sprites)
	{
		if (!playerDrawn && (obj->getBase() > player.getBase())) {
			playerInWater ? player.drawCropped(0, 7, rw) : player.draw(rw);			//cropping most of top
			player.drawBase(rw);	//temporary, just to see where bases ACTUALLY are.
			playerDrawn = true;
		}
		obj->draw(rw);
		obj->drawBase(rw);
	}
	if (!playerDrawn) {
		if (playerInWater) {
			player.move(0, 7*scale);
			player.drawCropped(0, 7, rw);
			player.move(0, -7*scale);

		} else {
			player.draw(rw);
		}
//		playerInWater ? player.drawCropped(0, 7, rw) : player.draw(rw);				//cropping most of top
	}
}

void MapSection::update(float elapsed) {
	for (auto && sprite : sprites) {
		sprite->update(elapsed);
	}
}

NodePtr MapSection::interact (std::vector<sf::FloatRect> collision) const {
	//see if I intersect any other sprites with bigger collision
	for (auto && sprite: sprites) {
		for (auto && box: collision) {
			if (sprite->intersects(box)) {
				//return corresponding ptr if DNode is not nullptr
				auto ptr = sprite->getDNode();
				if (ptr != nullptr) {
					return ptr;
				}
			}
		}
	}
	return nullptr;
}


sf::Vector2u MapSection::getSize()
{
	if (background.getTexture()) {
		sf::Vector2u area = background.getTexture()->getSize();
		area = sf::Vector2u(area.x * background.getScale().x, area.y * background.getScale().x);
		return area;
	} else {
		return sf::Vector2u(1000,1000);
	}
}

const SpriteVec& MapSection::getSpriteList()
{
	return sprites;
}

const ExitVec& MapSection::getExitList()
{
	return exits;
}

const TriggerVec& MapSection::getTriggerList()
{
	return triggers;
}

void MapSection::popTriggerAt(int index) {
	triggers.erase(triggers.begin()+index);
}

void MapSection::drawExits(sf::RenderWindow &rw) const {
	for (auto & exit : exits) {
		sf::FloatRect area = exit.getArea();
		sf::RectangleShape visibleExit;
		visibleExit.setPosition(area.left, area.top);
		visibleExit.setSize(sf::Vector2f(area.width, area.height));
		visibleExit.setFillColor(sf::Color(0,0,0,100));
		rw.draw(visibleExit);
	}
}









