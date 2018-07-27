//
//  TownSouth.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"
#include "DialogueMode.h"

class TownSouth: public MapSection
{
public:
	TownSouth(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~TownSouth() { std::cout << "Town South deleted.\n"; }
	
private:
	
};

