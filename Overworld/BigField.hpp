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

class BigField: public MapSection
{
public:
    BigField(const ResourceHolder& resources);
    ~BigField() {std::cout << "BigField deleted.\n";}
    
private:

};
