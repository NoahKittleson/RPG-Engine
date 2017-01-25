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
#include "TalkNode.h"
#include "OptionNode.h"
#include "PrefixHeader.pch"

class BigField: public MapSection
{
public:
    BigField(ResourceHolder& resources);
    ~BigField() {std::cout << "BigField deleted.\n";}
    
private:
    //very temporary, see below
    std::vector<MiniTrigger> testTriggers;
    //only here so that the pointers persist until map is destructed.
    std::vector<TalkNode> talkNodeHolder;
    std::vector<OptionNode> optionNodeHolder;
};
