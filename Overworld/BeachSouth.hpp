//
//  BeachSouth.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class BeachSouth: public MapSection
{
public:
	BeachSouth(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~BeachSouth() { std::cout << "Beach South deleted.\n"; }
	
private:
	
};
