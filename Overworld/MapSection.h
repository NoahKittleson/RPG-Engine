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
#include "InteractableSprite.h"
#include "ZoneExit.h"
#include "Player.h"

using ExitVec = std::vector<ZoneExit>;
using SpriteVec = std::vector<InteractableSprite>;
using TriggerVec = std::vector<Trigger>;


class MapSection: sf::NonCopyable
{
protected:
    sf::Sprite background;
    ExitVec exits;
    SpriteVec sprites;
    TriggerVec triggers;
    
    void addObject(InteractableSprite&);

    
public:
    MapSection(MapID id);
    const MapID ID;
    
    void drawBackground(sf::RenderWindow &rw);
    void drawAllObjects(sf::RenderWindow &rw, Player&);
    
    sf::Vector2u getSize();
    
    //collision detection that takes callback function for when collision is detected?
    
    SpriteVec& getSpriteList();
    const ExitVec& getExitList();
    const TriggerVec& getTriggerList();
};

