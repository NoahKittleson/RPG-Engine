//
//  MapFactory.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/11/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MapFactory.hpp"


std::unique_ptr<MapSection> MapFactory::create(MapID toCreate, const ResourceHolder& resources) {
	switch (toCreate) {
		case MapID::BeachNorth:
			return make_unique<BigField>(resources);
			break;
		
		case MapID::Start:
			return make_unique<Start>(resources);
			break;
			
		case MapID::BeachWest:
			return make_unique<BeachWest>(resources);
			break;
			
		default:
			break;
	}
}
