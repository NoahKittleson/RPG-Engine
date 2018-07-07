//
//  MountainSouth.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//


#pragma once
#include "MapSection.h"
#include "BattleState.h"

class MountainSouth: public MapSection
{
public:
	MountainSouth(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~MountainSouth() { std::cout << "Mountain South deleted.\n"; }
	
private:
	
};
