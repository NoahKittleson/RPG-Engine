//
//  Forest.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/7/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class Forest: public MapSection
{
public:
	Forest(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~Forest() { std::cout << "Forest deleted.\n"; }
	
private:
	
};
