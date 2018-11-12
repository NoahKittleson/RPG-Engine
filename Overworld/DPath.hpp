//
//  DPath.hpp
//  Overworld
//
//  Created by Noah Kittleson on 5/2/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#pragma once
#include "DialogueIDs.hpp"
#include "Conditions.hpp"
#include "PrefixHeader.pch"

struct DPath
{
public:
	DPath(Dialogue::ID next, std::vector<Condition> preReqs = std::vector<Condition>());
	bool isSatisfied(const std::vector<Condition> activeConds) const;
	Dialogue::ID getNext() const;
	
private:
	std::vector<Condition> preReqs;
	Dialogue::ID next;
};
