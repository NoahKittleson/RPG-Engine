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
#include "StaggeredAnimation.hpp"
#include "TalkNode.h"
#include "OptionNode.h"
#include "CharacterGenerator.hpp"
#include "DialogueFactory.hpp"
#include "AudioIDs.hpp"


using ExitVec = std::vector<ZoneExit>;
using SpriteVec = std::list<std::unique_ptr<MapObject>>;
using TriggerVec = std::vector<GroundTrigger>;


class MapSection: sf::NonCopyable
{
public:
	MapSection(MapID mapID, MusicID musicID, sf::Vector2f globalPos);
    const MapID ID;
	
	void update(float elapsed);
    void drawBackground(sf::RenderWindow &rw);
    void drawAllObjects(sf::RenderWindow &rw, MapObject& player);
	void drawAllBoxes(sf::RenderWindow& rw) const;
	void drawLighting(sf::RenderWindow& rw) const;
	
	NodePtr interact (std::vector<sf::FloatRect>) const;
    
    sf::Vector2u getSize();
    MusicID music;
    
    //collision detection that takes callback function for when collision is detected?
    
    const SpriteVec& getSpriteList();
    const ExitVec& getExitList();
    const TriggerVec& getTriggerList();
	const sf::Vector2f getGlobalPosition();
	
	void drawExits(sf::RenderWindow &rw) const;
	
	void popTriggerAt(int index);
	
protected:
	void addObject(MapObject& add);
	void setLighting(const sf::Texture& texture);

	sf::Sprite background;
	sf::Sprite lightingTexture;
	ExitVec exits;
	SpriteVec sprites;
	std::vector<sf::FloatRect> waterZones;
	TriggerVec triggers;
	
	static const int scale = 3;
	const int mapClearance = 20;
	const sf::Vector2f globalPosition;
};

