//
//  StartingZone.h
//  Overworld
//
//  Created by Noah Kittleson on 7/31/16.
//  Copyright © 2016 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "ResourceHolder.h"
#include "TalkNode.h"
#include "PrefixHeader.pch"

class StartingZone: public MapSection
{
public:
    StartingZone(ResourceHolder& resources);
    
    
private:
    //very temporary, see below
    std::vector<MiniTrigger> testTriggers;
    
};
