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


//void MapSection::addObject(InteractableSprite& add)
//{
//	for (auto it = sprites.begin(); it != sprites.end(); it++) {
//		if (add.getBase() < it->getBase()) {
//			sprites.insert(it, add);									//perhaps this /should/ be a list...
//			return;
//		}
//	}
//	sprites.push_back(add);
//}

void MapSection::drawBackground(sf::RenderWindow&rw)
{
	rw.draw(background);
}

std::string MapSection::getMusicAddress() {
	return resourcePath() + musicFilename;
}

void MapSection::drawAllObjects(sf::RenderWindow &rw, MapObject& player)
{
	bool playerDrawn = false;
	for (const auto & obj: sprites)
	{
		if (!playerDrawn && (obj.getBase() > player.getBase())) {
			player.draw(rw);
			player.drawBase(rw);	//temporary, just to see where bases ACTUALLY are.
			playerDrawn = true;
		}
		obj.draw(rw);
		obj.drawBase(rw);
	}
	if (!playerDrawn) {
		player.draw(rw);
	}
}

void MapSection::update(sf::RenderWindow &rw, float elapsed) {
	for (auto && sprite : sprites) {
		sprite.update(elapsed);

	}
}

DNode* MapSection::interact (std::vector<sf::FloatRect> collision) const {
	
	//see if I intersect any other sprites with bigger collision
	for (auto && sprite: sprites) {
		for (auto && box: collision) {
			if (sprite.intersects(box)) {
				//return corresponding ptr if DNode is not nullptr
				auto ptr = sprite.getDNode();
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
		return background.getTexture()->getSize();
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







