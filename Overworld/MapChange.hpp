//
//  MapChange.hpp
//  Overworld
//
//  Created by Noah Kittleson on 8/12/19.
//  Copyright © 2019 Noah. All rights reserved.
//

#pragma once
#include "Mode.hpp"
#include "MapFactory.hpp"
#include "OverworldMode.h"


class MapChange : public Mode {
public:
	MapChange(MapID changeTo);
	~MapChange();
	void update(float elapsed, State* context) override;
	void draw(sf::RenderWindow &rw) override;
	void handleInput(sf::RenderWindow &rw) override;
	
private:
	MapID changeTo;
	
};


//perhaps I need to have Fade be a feature of the base State class?  That takes over control?
//at that point, I'd have to have the modeStack basically be in state too, or at least approximate it there, in a place where it can
//take over from update, draw, and handleInput and only do Fade things instead.  However, then all states would have access to it,
//at the very least.
//
//class Behavior;
//
////these are the states
//class VirtualContext {
//	int x;
//	Behavior* behaviorPtr;
//	void act () {
//		behaviorPtr->function(this);
//	}
//};
//
//class SpecificContext : public VirtualContext {
//	int y;
//};
//
////these are the modes
//class Behavior {
//	virtual void function(VirtualContext*);
//};
//
//class SpecificBehavior : public Behavior {
//	void function(SpecificContext*) override;
//};

