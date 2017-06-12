//
//  Trigger.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "Trigger.h"



bool Trigger::intersects(sf::FloatRect box) const
{
    return area.intersects(box);
}

ActionID Trigger::proc(const std::vector<Condition>& conds) const {
    if (testConditions(conds)) {
        return successAction;
    } else
        return failureAction;
}

bool Trigger::testConditions(const std::vector<Condition>& conds) const {
    for(const auto & it : prerequisites) {
        bool active = std::find(conds.begin(), conds.end(), it.first) != conds.end();
        //if the flag's existence agrees with the condition prereq
        if (active == it.second) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

sf::FloatRect Trigger::getArea() const {
	return area;
}

