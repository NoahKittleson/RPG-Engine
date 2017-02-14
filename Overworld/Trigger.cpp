//
//  Trigger.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "Trigger.h"



bool Trigger::intersects(sf::IntRect box) const
{
    return area.intersects(box);
}

ActionID Trigger::proc(ConditionMap conds) const {
    if (testConditions(conds)) {
        return successAction;
    } else
        return failureAction;
}

bool Trigger::testConditions(ConditionMap conds) const {
    for(auto && it : prerequisites){
        if(it.second != conds[it.first]) {
            return false;
        }
    }
    return true;
}
