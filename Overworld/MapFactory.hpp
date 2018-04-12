//
//  MapFactory.hpp
//  Overworld
//
//  Created by Noah Kittleson on 4/11/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"

class MapFactory {
public:
	enum SectionName { StartingZone, BigField };
	static MapSection create();
	
private:
	
	
};
