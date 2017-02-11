//
//  ZoneExit.h
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "Player.h"

class ZoneExit
{
public:
    ZoneExit(sf::IntRect pos, sf::Vector2f offset, std::string nextZoneID);
    
    bool intersects(sf::IntRect) const;
    std::string getNextZone() const;
    void MoveSpriteToNewZone(Player&, sf::View&) const;         //a little jank... possible to change?
    
private:
    std::string newZoneID;
    const sf::IntRect area;
    const sf::Vector2f transitionOffset;
};

