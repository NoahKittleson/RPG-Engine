//
//  StaticComponent.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/16/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "GraphicsComponent.hpp"

class StaticComponent : public GraphicsComponent
{
    void update(MapSprite& spr, float elapsed) override;
};
