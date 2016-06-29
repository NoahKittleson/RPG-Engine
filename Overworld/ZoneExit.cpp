//
//  ZoneExit.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "ZoneExit.h"

ZoneExit::ZoneExit(sf::FloatRect pos, sf::Vector2f offset, MapSection* next)
: area(pos), transitionOffset(offset), newZone(next)
{
    
}

bool ZoneExit::intersects(sf::FloatRect rect) const
{
    return rect.intersects(area);
}

MapSection* ZoneExit::getNextZone() const
{
    return newZone;
}

void ZoneExit::MoveSpriteToNewZone(Player &player, sf::View &view) const
{
    player.move(transitionOffset.x, transitionOffset.y);
    view.move(transitionOffset);
}

