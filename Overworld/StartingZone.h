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
#include "OptionNode.h"
#include "PrefixHeader.pch"
#include "AnimatedComponent.hpp"
#include "DelayedAnimation.hpp"

class StartingZone: public MapSection
{
public:
    StartingZone(const ResourceHolder& resources);
    ~StartingZone() { std::cout << "StartingZone deleted.\n"; }
    
private:
    //very temporary, see below
    //only here so that the pointers persist until map is destructed.
    std::vector<TalkNode> talkNodeHolder;
    std::vector<OptionNode> optionNodeHolder;
};

//I need to find a way to have the spriteList ordered.  Since the copy assignment constructor is deleted (due to const members) I cannt use vector.insert() or other methods of reordering items.  Therefore, I have to put items into the list in the exact order that I want to have them by the end.
