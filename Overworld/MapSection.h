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
#include "Player.h"

using ExitVec = std::vector<ZoneExit>;
using SpriteVec = std::vector<MapObject>;
using TriggerVec = std::vector<Trigger>;


class MapSection: sf::NonCopyable
{
public:
    MapSection(MapID id, std::string musicFile);
    const MapID ID;
    
    void drawBackground(sf::RenderWindow &rw);
    void drawAllObjects(sf::RenderWindow &rw, Player&);
    
    sf::Vector2u getSize();
    std::string getMusicAddress();
    
    //collision detection that takes callback function for when collision is detected?
    
    SpriteVec& getSpriteList();
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

