//
//  Beach.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/24/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class BeachWest : public MapSection
{
public:
	BeachWest(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~BeachWest() { std::cout << "Beach West deleted.\n"; }
	
private:
	
};
