//
//  Trigger.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "Trigger.h"



bool Trigger::intersects(sf::IntRect box) const
{
    return area.intersects(box);
}

