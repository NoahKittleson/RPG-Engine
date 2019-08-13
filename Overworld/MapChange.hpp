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
