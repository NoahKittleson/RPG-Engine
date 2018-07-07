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
		case MapID::BeachNorth:
			return make_unique<BeachNorth>(resources, activeConds);
			break;
		
		case MapID::Start:
			return make_unique<Start>(resources, activeConds);
			break;
			
		case MapID::BeachWest:
			return make_unique<BeachWest>(resources, activeConds);
			break;
			
		default:
			break;
	}
}
