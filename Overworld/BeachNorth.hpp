//
//  BigField.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/24/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "BattleState.h"

class BeachNorth: public MapSection
{
public:
    BeachNorth(const ResourceHolder& resources, const std::vector<Condition>& activeConds);
    ~BeachNorth() {std::cout << "Beach North deleted.\n";}
    
private:

};
