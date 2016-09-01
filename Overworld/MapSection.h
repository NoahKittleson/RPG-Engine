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
#include "TalkingSprite.h"
#include "ZoneExit.h"
#include "Player.h"

class MiniTrigger;

using ExitVec = std::vector<ZoneExit>;
using SpriteVec = std::vector<TalkingSprite>;
//temporary change, see below
using TriggerVec = std::vector<Trigger>;
using MiniTriggerVec = std::vector<MiniTrigger>;


class MapSection: sf::NonCopyable
{
protected:
    sf::Sprite background;
    ExitVec exits;
    SpriteVec sprites;
    TriggerVec triggers;
    
    void addObject(TalkingSprite&);

    
public:
    MiniTriggerVec miniTriggers;
    //It may seem weird that Maps are not constructed with ExitVecs, but that is because ZoneExits point to other MapSections
    //MapSection(const sf::Texture&, SpriteVec&, TriggerVec&);
    MapSection();
    
    void drawBackground(sf::RenderWindow &rw);
    void drawAllObjects(sf::RenderWindow &rw, Player&);
    void addExit(sf::FloatRect pos, sf::Vector2f offset, std::string next);
    
    sf::Vector2u getSize();
    
    //collision detection that takes callback function for when collision is detected?
    
    SpriteVec& getSpriteList();
    const ExitVec& getExitList();
    const TriggerVec& getTriggerList();
};

//this class is only temporary to be able to trigger very rudimentary triggers.
class MiniTrigger
{
public:
    MiniTrigger (sf::FloatRect rect, std::string str) : zone(rect), actionID(str) { };
    sf::FloatRect getZone() const { return zone; }
    std::string getActionID() const { return actionID; }
private:
    sf::FloatRect zone;
    std::string actionID;
};

