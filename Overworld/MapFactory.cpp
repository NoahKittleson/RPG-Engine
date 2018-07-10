//
//  MapFactory.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/11/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MapFactory.hpp"


std::unique_ptr<MapSection> MapFactory::create(MapID toCreate, const ResourceHolder& resources, const std::vector<Condition>& activeConds) {
	switch (toCreate) {
		case MapID::MountainWest:
			return make_unique<MountainWest>(resources, activeConds);
			break;
			
		case MapID::MountainEast:
			return make_unique<MountainEast>(resources, activeConds);
			break;
			
		case MapID::BeachNorth:
			return make_unique<BeachNorth>(resources, activeConds);
			break;
			
		case MapID::MountainSouth:
			return make_unique<MountainSouth>(resources, activeConds);
			break;
			
		case MapID::TownEast:
			return make_unique<TownEast>(resources, activeConds);
			break;
			
		case MapID::BeachWest:
			return make_unique<BeachWest>(resources, activeConds);
			break;
			
		case MapID::Start:
			return make_unique<Start>(resources, activeConds);
			break;
			
		case MapID::SouthOfStart:
			return make_unique<SouthOfStart>(resources, activeConds);
			break;
			
		case MapID::Forest:
			return make_unique<Forest>(resources, activeConds);
			break;
			
		case MapID::Swamp:
			return make_unique<Swamp>(resources, activeConds);
			break;
			
		case MapID::BeachSouth:
			return make_unique<BeachSouth>(resources, activeConds);
			break;
			
		case MapID::TownSouth:
			return make_unique<TownSouth>(resources, activeConds);
			break;
			
		case MapID::LighthouseCoast:
			return make_unique<LighthouseCoast>(resources, activeConds);
			break;
	}
	std::cout << "grave error.  Trying to load non-existant map.  Exiting out.";
	assert(false);				//I should change this to something that won't be removed on release version
}
