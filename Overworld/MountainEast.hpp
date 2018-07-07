//
//  MountainEast.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/6/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class MountainEast: public MapSection
{
public:
	MountainEast(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~MountainEast() { std::cout << "Mountain East deleted.\n"; }
	
private:
	
};
