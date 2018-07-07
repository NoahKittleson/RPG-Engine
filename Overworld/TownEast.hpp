//
//  TownEast.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class TownEast: public MapSection
{
public:
	TownEast(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~TownEast() { std::cout << "Town East deleted.\n"; }
	
private:
	
};
