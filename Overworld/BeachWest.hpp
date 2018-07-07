//
//  Beach.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/24/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "MapSection.h"
#include "ResourceHolder.h"
#include "AnimatedComponent.hpp"
#include "DelayedAnimation.hpp"
#include "BattleState.h"
#include "TalkNode.h"
#include "OptionNode.h"
#include "CharacterGenerator.hpp"

class BeachWest : public MapSection
{
public:
	BeachWest(const ResourceHolder& resources);
	~BeachWest() { std::cout << "BeachWest deleted.\n"; }
	
private:
	
};
