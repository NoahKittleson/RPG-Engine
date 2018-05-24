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
		case MapID::BigField:
			return make_unique<BigField>(resources);
			break;
			
		case MapID::StartingZone:
			return make_unique<StartingZone>(resources);
			break;
			
		case MapID::Beach:
			return make_unique<Beach>(resources);
			break;
			
		default:
			break;
	}
}
