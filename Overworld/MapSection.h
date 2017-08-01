//
//  MapSection.h
//  Overworld
//
//  Created by Noah Kittleson on 6/4/15.
//  Copyright (c) 2015 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Trigger.h"
#include "MapObject.hpp"
#include "ZoneExit.h"
#include "ResourcePath.hpp"

using ExitVec = std::vector<ZoneExit>;
using SpriteVec = std::vector<MapObject>;
using TriggerVec = std::vector<Trigger>;


class MapSection: sf::NonCopyable
{
public:
    MapSection(MapID id, std::string musicFile);
    const MapID ID;
	
	void update(sf::RenderWindow &rw, float elapsed);
    void drawBackground(sf::RenderWindow &rw);
    void drawAllObjects(sf::RenderWindow &rw, MapObject& player);
	
	DNode* interact (std::vector<sf::FloatRect>) const;
    
    sf::Vector2u getSize();
    std::string getMusicAddress();
    
    //collision detection that takes callback function for when collision is detected?
    
    const SpriteVec& getSpriteList();
    const ExitVec& getExitList();
    const TriggerVec& getTriggerList();
	
protected:
	sf::Sprite background;
	ExitVec exits;
	SpriteVec sprites;
	TriggerVec triggers;
	const std::string musicFilename;
	
	//void addObject(InteractableSprite&);
	
	
};

