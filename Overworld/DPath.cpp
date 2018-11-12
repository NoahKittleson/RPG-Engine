//
//  DPath.cpp
//  Overworld
//
//  Created by Noah Kittleson on 5/2/18.
//  Copyright © 2018 Noah. All rights reserved.
//

#include "DPath.hpp"

DPath::DPath(Dialogue::ID next, std::vector<Condition> preReqs) : preReqs(preReqs), next(next) {
	
}

bool DPath::isSatisfied(const std::vector<Condition> activeConds) const {
	for (auto const & it : preReqs) {
		if (std::find(activeConds.begin(), activeConds.end(), it) == activeConds.end()) {
			return false;
		}
	}
	return true;
}

Dialogue::ID DPath::getNext() const {
	return next;
}
