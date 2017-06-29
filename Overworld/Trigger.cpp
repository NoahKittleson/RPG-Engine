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

void Trigger::drawArea(sf::RenderWindow& rw) const {
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(85,26,139, 150));		//translucent purple
	rect.setSize(sf::Vector2f(area.width, area.height));
	rect.setPosition(area.left, area.top);
	rw.draw(rect);
}


