//
//  PlayerObject.hpp
//  Overworld
//
//  Created by Noah Kittleson on 6/12/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "MapObject.hpp"
#include "MapSection.h"

class PlayerObject : public MapObject
{
public:
	NodePtr interact(const MapSection& map);
	PlayerObject(graphicsPtr&& gc);
	PlayerObject(graphicsPtr&& gc, RectVec& collision);
	
	
private:
	
	
};
