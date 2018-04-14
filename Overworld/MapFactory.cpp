//
//  MapFactory.cpp
//  Overworld
//
//  Created by Noah Kittleson on 4/11/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "MapFactory.hpp"


std::unique_ptr<MapSection> MapFactory::create(SectionName toCreate, ResourceHolder& resources) {
	switch (toCreate) {
		case BigField:
			return make_unique<BigField>(resources);
			break;
			
		case StartingZone:
			return make_unique<StartingZone>(resources);
			break;
			
		default:
			break;
	}
}
