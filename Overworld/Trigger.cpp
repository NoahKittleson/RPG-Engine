//
//  Trigger.cpp
//  Overworld
//
//  Created by Noah Kittleson on 2/26/16.
//  Copyright (c) 2016 Noah. All rights reserved.
//

#include "Trigger.h"

Trigger::Trigger(ConditionMap map, std::function<State*()> func)
:prereqs(map), makePtr(func)
{
}

bool Trigger::meetsReqs(ConditionVec& conds) const {
	bool requirementMet = true;
	for (auto && it : prereqs) {
		bool present = std::find(conds.begin(), conds.end(), it.first) == conds.end();
		if((!present && it.second) || (present && !it.second)) {
			requirementMet = false;
		}
	}
	return requirementMet;
}

GroundTrigger::GroundTrigger(ConditionMap& map, std::function<State*()> func, sf::FloatRect rect)
: Trigger(map, func), area(rect)
{
}

State* Trigger::proc(ConditionVec& conds) const {
	if (meetsReqs(conds)) {
		return makePtr();					//problem here is that you can't have unique_ptr with incomplete type
	}
	return nullptr;
}

bool GroundTrigger::intersects(std::vector<sf::FloatRect>& collision) {
	for (const auto & it : collision) {
		if(it.intersects(area)) {
			return true;
		}
	}
	return false;
}

GroundTrigger::operator sf::FloatRect() const {return area;};
void GroundTrigger::drawArea(sf::RenderWindow& rw) const {
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(85,26,139, 150));					//translucent purple
	rect.setSize(sf::Vector2f(area.width, area.height));
	rect.setPosition(area.left, area.top);
	rw.draw(rect);
};

AttachedTrigger::AttachedTrigger(ConditionMap map, std::function<State*()> func)
: Trigger(map, func)
{
}






