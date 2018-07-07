//
//  BigField.hpp
//  Overworld
//
//  Created by Noah Kittleson on 1/24/17.
//  Copyright © 2017 Noah. All rights reserved.
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

class BeachNorth: public MapSection
{
public:
    BeachNorth(const ResourceHolder& resources);
    ~BeachNorth() {std::cout << "Beach North deleted.\n";}
    
private:

};
