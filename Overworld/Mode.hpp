//
//  Mode.hpp
//  Overworld
//
//  Created by Noah Kittleson on 3/10/17.
//  Copyright © 2017 Noah. All rights reserved.
//

#pragma once
#include "PrefixHeader.pch"
#include "State.h"

class Mode {	
public:
    virtual ~Mode();
    virtual void update(float elapsed, State* context) = 0;
    virtual void draw(sf::RenderWindow &rw) = 0;
    virtual void handleInput(sf::RenderWindow &rw) = 0;
	
	virtual bool isDone() const;
	
protected:
	bool done = false;
};
