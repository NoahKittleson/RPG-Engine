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
#include "ZoneExit.h"
#include "MapObject.hpp"
#include "ResourcePath.hpp"

#include "ResourceHolder.h"
#include "AnimatedComponent.hpp"
#include "DelayedAnimation.hpp"
#include "TalkNode.h"
#include "OptionNode.h"
#include "CharacterGenerator.hpp"
#include "DialogueFactory.hpp"


using ExitVec = std::vector<ZoneExit>;
using SpriteVec = std::list<std::unique_ptr<MapObject>>;
using TriggerVec = std::vector<GroundTrigger>;


class MapSection: sf::NonCopyable
{
public:
	MapSection(MapID id, std::string musicFile);
    const MapID ID;
	
	void update(float elapsed);
    void drawBackground(sf::RenderWindow &rw);
    void drawAllObjects(sf::RenderWindow &rw, MapObject& player);
	void drawAllBoxes(sf::RenderWindow& rw) const;
	
	NodePtr interact (std::vector<sf::FloatRect>) const;
    
    sf::Vector2u getSize();
    std::string getMusicAddress();
    
    //collision detection that takes callback function for when collision is detected?
    
    const SpriteVec& getSpriteList();
    const ExitVec& getExitList();
    const TriggerVec& getTriggerList();
	
	void drawExits(sf::RenderWindow &rw) const;
	
	void popTriggerAt(int index);
	
protected:
	void addObject(MapObject& add);

	sf::Sprite background;
	ExitVec exits;
	SpriteVec sprites;
	std::vector<sf::FloatRect> waterZones;
	TriggerVec triggers;
	const std::string musicFilename;
	
	int scale = 3;
};

