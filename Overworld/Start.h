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

//I need to find a way to have the spriteList ordered.  Since the copy assignment constructor is deleted (due to const members) I cannt use vector.insert() or other methods of reordering items.  Therefore, I have to put items into the list in the exact order that I want to have them by the end.
