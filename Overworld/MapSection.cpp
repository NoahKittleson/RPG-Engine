//
//  MapSection.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/4/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "MapSection.h"


//Deleted for now because copying SpriteVec and TriggerVec is not a great idea
//(and any map instantiation should be derived from MapSection)
//MapSection::MapSection(const sf::Texture& bg, SpriteVec& sv,  TriggerVec& tv)
//: triggers(tv)
//{
//	background.setTexture(bg);
//	for (auto & it: sv) {
//		addObject(it);
//	}
//}

MapSection::MapSection() {
	//should this be empty?
};


void MapSection::addObject(TalkingSprite& add)
{
	for (auto it = sprites.begin(); it != sprites.end(); it++) {
		if (add.getPosition().y < it->getPosition().y) {
			sprites.insert(it, add);									//perhaps this /should/ be a list...
			return;
		}
	}
	sprites.push_back(add);
}

void MapSection::drawBackground(sf::RenderWindow&rw)
{
	rw.draw(background);
}

void MapSection::drawAllObjects(sf::RenderWindow &rw, Player& player)
{
	bool playerDrawn = false;
	for (const auto & obj: sprites)
	{
		if (!playerDrawn && (obj.getPosition().y > player.getPosition().y)) {
			rw.draw(player);
			playerDrawn = true;
		}
		rw.draw(obj);
	}
	if (!playerDrawn) {
		rw.draw(player);
	}
}

void MapSection::addExit(sf::FloatRect pos, sf::Vector2f offset, std::string next)
{
	exits.emplace_back(pos, offset, next);
}

sf::Vector2u MapSection::getSize()
{
	return background.getTexture()->getSize();
}

SpriteVec& MapSection::getSpriteList()
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







