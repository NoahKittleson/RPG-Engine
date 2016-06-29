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


using ExitVec = std::vector<ZoneExit>;
using SpriteVec = std::vector<TalkingSprite>;
using TriggerVec = std::vector<Trigger>;


class MapSection: sf::NonCopyable
{
public:
    MapSection(const sf::Texture&, SpriteVec&,  TriggerVec&);
    
    void drawBackground(sf::RenderWindow &rw);
    void drawAllObjects(sf::RenderWindow &rw, Player&);
    void addExit(sf::FloatRect pos, sf::Vector2f offset, MapSection* next);
    
    sf::Vector2u getSize();
    
    SpriteVec& getSpriteList();
    const ExitVec& getExitList();
    const TriggerVec& getTriggerList();
    
private:
    void addObject(TalkingSprite&);
    sf::Sprite background;
    ExitVec exits;
    SpriteVec sprites;
    TriggerVec triggers;
};