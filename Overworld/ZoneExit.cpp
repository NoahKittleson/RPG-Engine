//
//  ZoneExit.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "ZoneExit.h"

ZoneExit::ZoneExit(sf::IntRect pos, sf::Vector2f offset, MapID nextZone)
: area(pos), transitionOffset(offset), newZone(nextZone)
{
}

MapID ZoneExit::getNextZone() const
{
    return newZone;
}

sf::Vector2f ZoneExit::getMoveOffset() const {
    return transitionOffset;
}

sf::IntRect ZoneExit::getArea(){
	return area;
}
