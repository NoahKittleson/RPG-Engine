//
//  MapSection.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/4/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#include "MapSection.h"


MapSection::MapSection(sf::String filename, ZE_List& Exits, IO_List& Objlist, AZptr_List& trigs)
: exitList(Exits), triggerList(trigs)
{
    backgroundTexture.loadFromFile(filename);
	for (auto & it: Objlist) {
		addObject(it);
	}
}

void MapSection::AddExit(sf::FloatRect pos, sf::Vector2f offset, MapSection* next)
{
	exitList.emplace_back(pos, offset, next);
}

void MapSection::addObject(const InteractableObject& addMe)
{
	for (auto it = objList.begin(); it != objList.end(); it++) {
		if (addMe.getPosition().y < it->getPosition().y) {
			objList.insert(it, addMe);
			return;
		}
	}
	objList.push_back(addMe);
}

void MapSection::DrawAllObjects(sf::RenderWindow &rw, Player& player)
{
	bool playerDrawn = false;
	for (const auto & obj: objList)
	{
		if (!playerDrawn && (obj.getPosition().y > player.getPosition().y)) {
			player.draw(rw);
			playerDrawn = true;
		}
		obj.draw(rw);
	}
	if (!playerDrawn) {
		player.draw(rw);
	}
}

const sf::Texture& MapSection::getBackground()
{
	return backgroundTexture;
}

IO_List& MapSection::getObjectList()
{
	return objList;
}

const ZE_List& MapSection::getExitList()
{
	return exitList;
}

const AZptr_List& MapSection::getTriggerList()
{
	return triggerList;
}

sf::FloatRect ZoneExit::getCoordinates() const
{
	return coordinates;
}

MapSection* ZoneExit::getNextZone() const
{
	return newZone;
}

void ZoneExit::MoveSpriteToNewZone(Player &player, sf::View &view) const
{
	player.move(coordinateOffset.x, coordinateOffset.y);
	view.move(coordinateOffset);
}








