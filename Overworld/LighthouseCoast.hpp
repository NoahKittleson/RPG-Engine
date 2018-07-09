//
//  LighthouseCoast.hpp
//  Overworld
//
//  Created by Noah Kittleson on 7/8/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class LighthouseCoast: public MapSection
{
public:
	LighthouseCoast(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
	~LighthouseCoast() { std::cout << "Lighthouse Coast deleted.\n"; }
	
private:
	
};

