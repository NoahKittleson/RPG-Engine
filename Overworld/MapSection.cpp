//
//  MapSection.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/4/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "MapSection.h"


MapSection::MapSection(MapID mapID, MusicID musicID, sf::Vector2f globalPos) : ID(mapID), music(musicID), globalPosition(globalPos) {
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

void MapSection::drawLighting(sf::RenderWindow& rw) const {
	rw.draw(lightingTexture);
}


void MapSection::drawAllObjects(sf::RenderWindow &rw, MapObject& player) {
	bool playerDrawn = false;
	bool playerInWater = false;
	for (const auto & zone : waterZones) {		//perhaps I should calculate in-water-ness during update()?
		if (player.intersects(zone)) {
			playerInWater = true;
			break;
		}
	}
	
	//drawing feet NOW, if in water (so they can get covered by water)
	if (playerInWater) {
		player.move(0, 14 * scale);
		player.drawCropped(0, -14, rw);
		player.move(0, -14 * scale);				
	}
	
	for (const auto & obj: sprites)
	{
		if (!playerDrawn && (obj->getBase() > player.getBase())) {
			if (playerInWater) {
				player.drawCropped(0, 2, rw);
			} else {
				player.draw(rw);
			}
			playerDrawn = true;
		}
		obj->draw(rw);
	}
	if (!playerDrawn) {
		if (playerInWater) {
			player.drawCropped(0, 2, rw);
		} else {
			player.draw(rw);
		}
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
				std::cout << "Intersection Found\n";
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

void MapSection::drawAllBoxes(sf::RenderWindow &rw) const {
	//collision boxes and bases
	for (auto & sprite: sprites) {
		sprite->drawCollision(rw);
		sprite->drawBase(rw);
	}
	
	//triggers
	for (auto & it: triggers) {
		it.drawArea(rw);
	}
	
	//water
	for (auto & it: waterZones) {
		sf::RectangleShape waterBox;
		waterBox.setFillColor(sf::Color(0,250,0,50));
		waterBox.setPosition(it.left, it.top);
		waterBox.setSize(sf::Vector2f(it.width, it.height));
		rw.draw(waterBox);
	}
}

const sf::Vector2f MapSection::getGlobalPosition() {
	return globalPosition;
}










