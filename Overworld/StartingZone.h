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
#include "AnimatedComponent.hpp"
#include "DelayedAnimation.hpp"
#include "BattleMode.h"
#include "TalkNode.h"
#include "OptionNode.h"
#include "CharacterGenerator.hpp"

class StartingZone: public MapSection
{
public:
    StartingZone(const ResourceHolder& resources);
    ~StartingZone() { std::cout << "StartingZone deleted.\n"; }
    
private:
    //these should be owned by the items that use them.
	std::vector<TalkNode> talkNodeHolder;
	std::vector<OptionNode> optionNodeHolder;
	
};

//I need to find a way to have the spriteList ordered.  Since the copy assignment constructor is deleted (due to const members) I cannt use vector.insert() or other methods of reordering items.  Therefore, I have to put items into the list in the exact order that I want to have them by the end.
