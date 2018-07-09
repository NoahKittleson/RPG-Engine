//
//  MapFactory.hpp
//  Overworld
//
//  Created by Noah Kittleson on 4/11/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "MountainWest.hpp"
#include "MountainEast.hpp"
#include "BeachNorth.hpp"
#include "MountainSouth.hpp"
#include "TownEast.hpp"
#include "BeachWest.hpp"
#include "Start.h"
#include "SouthOfStart.hpp"
#include "Forest.hpp"
#include "Swamp.hpp"
#include "BeachSouth.hpp"
#include "TownSouth.hpp"
#include "LighthouseCoast.hpp"

class MapFactory {
public:
	//MapID list can be found in ZoneExit for whatever reason
	static std::unique_ptr<MapSection> create(MapID toCreate, const ResourceHolder& resources, const std::vector<Condition>& activeConds);
};
