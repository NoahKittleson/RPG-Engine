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

enum class ZoneID {Starting, BigField};

class ZoneExit
{
public:
    ZoneExit(sf::IntRect pos, sf::Vector2f offset, ZoneID nextZone);
    
    bool intersects(sf::IntRect) const;
    ZoneID getNextZone() const;
    sf::Vector2f getMoveOffset() const;
    
private:
    ZoneID newZone;
    const sf::IntRect area;
    const sf::Vector2f transitionOffset;
};

