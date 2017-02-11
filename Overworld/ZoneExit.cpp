//
//  ZoneExit.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "ZoneExit.h"

ZoneExit::ZoneExit(sf::IntRect pos, sf::Vector2f offset, std::string nextZoneID)
: area(pos), transitionOffset(offset), newZoneID(nextZoneID)
{
    
}

bool ZoneExit::intersects(sf::IntRect rect) const
{
    return rect.intersects(area);
}

std::string ZoneExit::getNextZone() const
{
    return newZoneID;
}

void ZoneExit::MoveSpriteToNewZone(Player &player, sf::View &view) const
{
    player.move(transitionOffset.x, transitionOffset.y);
    view.move(transitionOffset);
}

