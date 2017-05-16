//
//  GraphicsComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "MapSprite.hpp"

class GraphicsComponent
{
public:
    virtual ~GraphicsComponent() {}
    virtual void update(MapSprite& spr, float elapsed) = 0;
};
