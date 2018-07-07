//
//  MountainWest.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class MountainWest: public MapSection
{
public:
	MountainWest(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~MountainWest() { std::cout << "Mountain West deleted.\n"; }
	
private:
	
};
