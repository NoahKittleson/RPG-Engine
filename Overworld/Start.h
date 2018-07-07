//
//  StartingZone.h
//  Overworld
//
//  Created by Noah Kittleson on 7/31/16.
//  Copyright © 2016 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class Start: public MapSection
{
public:
    Start(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
    ~Start() { std::cout << "Start Zone deleted.\n"; }
    
private:
	
};
