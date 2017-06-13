//
//  PlayerObject.cpp
//  Overworld
//
//  Created by Noah Kittleson on 6/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#include "PlayerObject.hpp"


PlayerObject::PlayerObject(GraphicsComponent* gc, RectVec& collision)
: MapObject(gc, collision, nullptr)
{
	
}

PlayerObject::interact(const MapSection *map) {
	for (auto && const it: sprites) {
		<#statements#>
	}
}
