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
    ZoneExit(sf::FloatRect pos, sf::Vector2f offset, std::string nextZoneID);
    
    bool intersects(sf::FloatRect) const;
    std::string getNextZone() const;
    void MoveSpriteToNewZone(Player&, sf::View&) const;         //a little jank... possible to change?
    
private:
    std::string newZoneID;
    const sf::FloatRect area;
    const sf::Vector2f transitionOffset;
};

