//
//  MapFactory.hpp
//  Overworld
//
//  Created by Noah Kittleson on 4/11/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BigField.hpp"
#include "StartingZone.h"

class MapFactory {
public:
	//MapID list can be found in ZoneExit for whatever reason
	static std::unique_ptr<MapSection> create(MapID toCreate, const ResourceHolder& resources);
};
