//
//  ZoneExit.h
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
//#include "MapSection.h"
#include "Player.h"

class MapSection;

class ZoneExit
{
public:
    ZoneExit(sf::FloatRect pos, sf::Vector2f offset, MapSection* next);
    
    bool intersects(sf::FloatRect) const;
    MapSection* getNextZone() const;
    void MoveSpriteToNewZone(Player&, sf::View&) const;         //a little jank... possible to change?
    
private:
    MapSection* newZone;
    const sf::FloatRect area;
    const sf::Vector2f transitionOffset;
};

