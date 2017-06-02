//
//  ZoneExit.h
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "MapObject.hpp"

enum class MapID {Starting, BigField};

class ZoneExit
{
public:
    ZoneExit(sf::IntRect pos, sf::Vector2f offset, MapID nextZone);
    
    MapID getNextZone() const;
    sf::Vector2f getMoveOffset() const;
	sf::IntRect getArea() const;
	
private:
    const MapID newZone;
    const sf::IntRect area;
    const sf::Vector2f transitionOffset;
};

