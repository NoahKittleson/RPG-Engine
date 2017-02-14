//
//  ZoneExit.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "ZoneExit.h"

ZoneExit::ZoneExit(sf::IntRect pos, sf::Vector2f offset, ZoneID nextZone)
: area(pos), transitionOffset(offset), newZone(nextZone)
{
    
}

bool ZoneExit::intersects(sf::IntRect rect) const
{
    return rect.intersects(area);
}

ZoneID ZoneExit::getNextZone() const
{
    return newZone;
}

sf::Vector2f ZoneExit::getMoveOffset() const {
    return transitionOffset;
}
