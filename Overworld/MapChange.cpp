//
//  MapChange.cpp
//  Overworld
//
//  Created by Noah Kittleson on 8/12/19.
//  Copyright © 2019 Noah. All rights reserved.
//

#include "MapChange.hpp"


void MapChange::update(float elapsed, State* context) {
	//context->changeMap(changeTo);
}

void MapChange::draw(sf::RenderWindow &rw) {
	//possibly have a loading bar eventually?  But for now a black screen is totally fine.
	rw.clear(sf::Color::Black);
}

void MapChange::handleInput(sf::RenderWindow &rw) {
	//no input handling in this mode
	return;
}
