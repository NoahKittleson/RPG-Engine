//
//  SouthOfStart.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class SouthOfStart: public MapSection
{
public:
	SouthOfStart(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~SouthOfStart() { std::cout << "South Of Start deleted.\n"; }
	
private:
	
};
