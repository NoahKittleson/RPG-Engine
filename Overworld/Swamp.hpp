//
//  Swamp.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class Swamp: public MapSection
{
public:
	Swamp(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~Swamp() { std::cout << "Swamp deleted.\n"; }
	
private:
	
};
